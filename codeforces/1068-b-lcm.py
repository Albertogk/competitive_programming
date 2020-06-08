import math

b = int(input())

i = 2
result = 2
if b == 1 or b == 2:
    print(b)

else:
    while i < math.sqrt(b):
        flag = False
        if b%i == 0:
            result += 2

        i += 1

    if i == math.sqrt(b):
        result += 1

    print(result)
