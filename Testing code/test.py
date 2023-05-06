import os
a = 20
while a:
    # os.system('./generator ' + str(seed) + ' > input.txt')
    os.system('generator_code.exe > input.txt')
    os.system('Solution_code.exe < input.txt > Solution_code.txt')
    os.system('Test_code.exe < input.txt > Test_code.txt')
    if open('Solution_code.txt').read() != open('Test_code.txt').read():
        print('WA')
        exit(0)
    print("# Test case ", (100-a+1), " completed")
    a -= 1

print('Accept')
exit(0)
