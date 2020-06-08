t = int(input())

for i in range(t):
    for j in [0, 3, 6, 1, 4, 7, 2, 5, 8]:
        line = list(input())
        line[j] = str(int(line[j]) % 9 + 1)
        print(''.join(line))