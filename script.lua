-- script.lua
--printMessage_const("You can call C++ functions from Lua!")

sumNumbers = function(a,b)
    --printMessage_const("You can still call C++ functions from Lua functions!")
    return a + b
end

--Obj = ObjectManager()
--P = Obj:GetTest("test_object")
--var = P:GetTest("test_player")
--printMessage_const(var)

print(temp.t.text)
temp.t.text = "to C"
tem1 = temp.t.text
print(tem1)
print(temp.t.text)
print("----------")
t2 = test()
print(t2.text)
t2.text = "t2 to C"
print(t2.text)
print("----------")
