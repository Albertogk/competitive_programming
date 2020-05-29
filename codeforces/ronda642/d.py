t = int(input())

for i in range(t):
    n = int(input())
    arr = [0]*n
    cnt = 1
    while 0 in arr:
        l = 0
        r = 0
        max_len = 0
        len_actual = 0
        for j in range(n):
            if arr[j] == 0:
                len_actual += 1
                if len_actual > max_len:
                    max_len = len_actual
                    r = j
                    l = j-len_actual+1
            else:
                len_actual = 0

        if r-l+1 % 2 != 0:
            arr[int((l+r)/2)] = cnt
        else:
            arr[int((l + r - 1) / 2)] = cnt
        cnt += 1

    arr = list(map(lambda x: str(x), arr))
    print(' '.join(arr))