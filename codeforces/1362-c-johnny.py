import math

t = int(input())
for i in range(t):
    n = int(input())
    prev_total = -1
    total = 0
    cnt = 0
    while total != prev_total:
        prev_total = total
        total += (math.ceil(n >> cnt))
        cnt += 1

    print(total)
