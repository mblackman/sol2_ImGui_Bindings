#!/usr/bin/env bash
# Regenerate codegen/metadata/dcimgui.json from the Dear ImGui headers the
# library is actually built against, using a pinned dear_bindings.
#
# Usage:
#   codegen/fetch_metadata.sh <path-to-imgui-include-dir>
#
# The include dir must contain imgui.h and imconfig.h (e.g. a vcpkg
# x64-linux/include directory). dear_bindings is cloned at a pinned SHA into
# codegen/.dear_bindings (gitignored) so the result is reproducible without a
# nested git submodule.
set -euo pipefail

# Pinned dear_bindings revision. Bump deliberately when moving to an ImGui
# version that needs a newer generator (see CONTRIBUTING.md).
DEAR_BINDINGS_REPO="https://github.com/dearimgui/dear_bindings"
DEAR_BINDINGS_SHA="c9ff64913915df41c0f4beef485b98a1c685eda5"

here="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
imgui_inc="${1:-}"

if [[ -z "$imgui_inc" || ! -f "$imgui_inc/imgui.h" || ! -f "$imgui_inc/imconfig.h" ]]; then
  echo "error: pass an ImGui include dir containing imgui.h and imconfig.h" >&2
  echo "usage: $0 <path-to-imgui-include-dir>" >&2
  exit 2
fi

db_dir="$here/.dear_bindings"
if [[ ! -d "$db_dir/.git" ]]; then
  git clone "$DEAR_BINDINGS_REPO" "$db_dir"
fi
git -C "$db_dir" fetch --quiet origin "$DEAR_BINDINGS_SHA" || true
git -C "$db_dir" checkout --quiet "$DEAR_BINDINGS_SHA"

# Use a throwaway venv so the host Python stays clean.
venv="$here/.venv"
if [[ ! -x "$venv/bin/python" ]]; then
  python3 -m venv "$venv"
fi
"$venv/bin/pip" install --quiet -r "$here/requirements.txt"

out_base="$here/metadata/dcimgui"
"$venv/bin/python" "$db_dir/dear_bindings.py" \
  --imconfig-path "$imgui_inc/imconfig.h" \
  -o "$out_base" \
  "$imgui_inc/imgui.h"

# dear_bindings also emits a C header/source we do not use; keep only the JSON.
rm -f "$out_base.h" "$out_base.cpp"

echo "wrote $out_base.json"
