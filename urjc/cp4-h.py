t = int(input())
max = 0
max_idx = 0
nombres = []
for i in range(0, t):
    sum = 0
    l = input().split()
    n = int(l[0])
    nombres.append(l[1])
    for j in range(0, n):
        l = input().split()
        sum += int(l[1])

    if sum > max:
        max = sum
        max_idx = i

print(nombres[max_idx], max)