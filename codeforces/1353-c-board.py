t = int(input())

for i in range(t):
    n = int(input())
    result = 0
    n_c = 3
    for j in range(1, int(n/2)+1):
        result += (2*n_c + 2*(n_c-2))*j
        n_c += 2

    print(result)