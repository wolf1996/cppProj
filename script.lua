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

print(temp.t_ob.pt)
temp.t_ob.pt = "to C"
print(temp.t_ob.pt)



table1 = {
    value = 42,
    name = "автостопом по галактике",
    table_inside = {
        author = "bla bla",
        date = 1999,
    },
}

var = {
    boards = {
        wordboard,
    },
    decks  = {
        gamecards = {
            {
                {
                    back = "1",
                    face = "2",
                    props = {},
                },
                {
                    back = "1",
                    face = "2",
                    props = {},
                },
                {
                    back = "1",
                    face = "2",
                    props = {},
                },
            },
        },
    },
    cardholders = {
        picholder,
        numholder
    },
    fields = {
        gamefield = { num = 26,
        },
    },
    player = {
        chips = {
            gamefield,
        },
        decks = {
            numdeck = {
            {
                back = "1",
                face = "2",
                props = { num = 1 },
            },
            {
                back = "1",
                face = "2",
                props = {num = 2 },
            },
            {
                back = "1",
                face = "2",
                props = {num = 3},
            },
            }
        }

    },
}
