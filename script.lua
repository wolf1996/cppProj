-- script.lua
printMessage_const("You can call C++ functions from Lua!")

sumNumbers = function(a,b)
    printMessage_const("You can still call C++ functions from Lua functions!")
    return a + b
end

Obj = ObjectManager()
P = Obj:GetTest("test_object")
var = P:GetTest("test_player")
printMessage_const(var)
