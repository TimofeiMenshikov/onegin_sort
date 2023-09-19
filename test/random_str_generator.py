import random


n_strings = 100

min_str_len = 5
max_str_len = 15

with open("../onegin.txt", "w") as write_file:
    

    for i in range(n_strings):
        strlen = random.randint(min_str_len, max_str_len)
        
        for j in range(strlen):
            write_file.write(chr(ord('a') + random.randint(0, 25)))
            
        write_file.write('\n')