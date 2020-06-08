n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
solution = [0]*n
distances = [-1]*n
sol = 0

for i in range(n):
    ele = b[i] - 1
    distances[ele] = i

for i in range(n):
    ele = a[i]-1

    aux = i - distances[ele]
    if aux < 0:
        aux = n+aux

    solution[aux] += 1
    if solution[aux] > sol:
        sol = solution[aux]


print(sol)