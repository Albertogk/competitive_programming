t = int(input())

for i in range(t):
    n, k = list(map(int, input().split()))

    a = list(map(int, input().split()))
    b = list(map(int, input().split()))

    a.sort()
    b.sort(reverse=True)

    candidates_a = a[:k]
    candidates_b = b[:k]
    suma = sum(a)

    idx = 0
    while idx < k:
        if candidates_a[idx] < candidates_b[idx]:
            suma -= candidates_a[idx]
            suma += candidates_b[idx]
            idx += 1

        else:
            break

    print(suma)
