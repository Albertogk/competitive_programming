t = int(input())

for i in range(t):
    x1, y1, x2, y2 = list(map(int, input().split()))

    x2 = x2-x1
    y2 = y2-y1

    print(x2*y2+1)