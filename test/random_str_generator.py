import random


n_strings = 40

min_str_len = 5
max_str_len = 15

with open("../txt/input/onegin.txt", "w") as write_file:
    

    for i in range(n_strings):
        strlen = random.randint(min_str_len, max_str_len)
        
        for j in range(strlen):
            write_file.write(chr(random.randint(35, 125)))
            
        write_file.write('\n')