t = int(input())

for i in range(t):
    n, k = list(map(int, input().split()))
    a = list(map(int, input().split()))
    p = 0
    l = 0
    n_p = 0
    for i in range(2, n):
        if a[i] < a[i-1] and a[i-1] > a[i-2]:
            n_p += 1

        if i == k-1:
            p = n_p

        if i >= k:
            if a[i-k+1] > a[i- k] and a[i-k+1] > a[i-k +2]:
                n_p -= 1

            if n_p > p:
                l = i-k+1
                p = n_p

    print(p+1, l+1)