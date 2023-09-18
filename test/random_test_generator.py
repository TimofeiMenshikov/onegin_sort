import random

with open("test_sort.txt", "w") as test_file:
    
    n_tests = 30
    
    test_file.write(str(n_tests))
    test_file.write("\n")

    for n_test in range(n_tests):

        size = random.randint(1, 30)

        array = []

        for int_number in range(size):
            array.append(str(random.randint(1, 9)))
            
        test_file.write(str(size))
        test_file.write("\n")
        test_file.write(" ".join(array))
        test_file.write("\n")
        array.sort()
        test_file.write(" ".join(array))
        test_file.write("\n")

