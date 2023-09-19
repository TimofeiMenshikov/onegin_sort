with open("onegin.txt") as file:
    a = file.readlines()
    b = list(a)

with open("onegin_test.txt", "w") as file_test:
    for i in range(len(b)):
        if b[i] != "\n":
                
            for j in range(len(b[i])):
                file_test.write(str(b[i][j]))
            
    