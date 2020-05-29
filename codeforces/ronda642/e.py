t = int(input())

for i in range(t):
    n, k = list(map(lambda x: int(x), input().split()))
    lamps = input()
    for j in range(k):
        aux = '0'*k
        aux[j] = '1'
        aux = aux*int((n/k)+1)
        aux = aux[:n]

