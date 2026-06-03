-- Callability smoke test: runs inside a live (headless) ImGui frame.
-- Exercises a representative slice of generated + manual bindings and asserts
-- the value-first return-shape convention that Lua callers depend on.

-- enums are registered as globals (matching the original API) and numeric
assert(type(ImGuiWindowFlags.NoTitleBar) == "number", "window flag enum")
assert(type(ImGuiCol.Text) == "number", "col enum")
assert(type(ImGuiCond.Always) == "number", "cond enum")
-- a flag that the hand-written bindings never exposed (full coverage win)
assert(type(ImGuiButtonFlags.MouseButtonRight) == "number", "new enum coverage")

-- ImVec2 usertype
local v = ImVec2.new(3, 4)
assert(v.x == 3 and v.y == 4, "ImVec2 fields")

-- manual: Begin single-return form, then a window body
local visible = ImGui.Begin("smoke")
assert(type(visible) == "boolean", "Begin single return")

-- generated: simple void / bool / value widgets
ImGui.Text("hello")
ImGui.Separator()
local clicked = ImGui.Button("ok")
assert(type(clicked) == "boolean", "Button returns bool")

-- generated: output-pointer widgets return (value, used) -- value first
assert(select("#", ImGui.SliderFloat("s", 0.5, 0.0, 1.0)) == 2, "SliderFloat arity")
local sv = ImGui.SliderFloat("s", 0.5, 0.0, 1.0)
assert(math.abs(sv - 0.5) < 1e-6, "SliderFloat value-first")

assert(select("#", ImGui.InputInt("i", 3)) == 2, "InputInt arity")
local iv = ImGui.InputInt("i", 3)
assert(iv == 3, "InputInt value-first")

local fv = ImGui.InputFloat("f", 1.25)
assert(math.abs(fv - 1.25) < 1e-6, "InputFloat value-first")

-- manual: combo with a Lua item list (1-based index in/out)
local items = {"a", "b", "c"}
local ci = ImGui.Combo("combo", 1, items, 3)
assert(ci == 1, "Combo value-first")

-- manual: default-arg collapse via sol::optional (flags omitted)
local txt = ImGui.InputText("name", "value", 64)
assert(txt == "value", "InputText round-trip")

-- manual: array widget returns a table + used
local arr = ImGui.DragFloat2("xy", {1.0, 2.0})
assert(arr[1] == 1.0 and arr[2] == 2.0, "DragFloat2 table round-trip")

ImGui.End()

print("smoke.lua: all assertions passed")
