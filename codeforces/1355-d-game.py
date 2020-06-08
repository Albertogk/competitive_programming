
n, s = list(map(int, input().split()))
if s < 2*n:
    print("NO")

else:
    print("YES")
    sol = []
    ele = s // n
    for i in range(n-1):
        sol.append(str(ele))

    sol.append(str(s-len(sol)*ele))
    print(' '.join(sol))
    print(1)
