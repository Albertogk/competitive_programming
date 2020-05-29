
i = 0
modes = {0: 'shata', 1: 'hajar', 2: 'lakh', 3: 'kuti'}

while 1:
    i+=1
    try:
        n = input()
        result = []
        idx_inf = -3
        idx_sup = -2
        mode = 0

        if n[-2:] != '00':
            result.append(str(int(n[-2:])))

        while 1:
            if idx_sup <= -len(n):
                break

            if idx_inf < -len(n):
                idx_inf = -len(n)

            aux = n[idx_inf:idx_sup]
            if aux != '0'*len(aux):
                result.append(modes[mode])
                result.append(str(int(aux)))

            elif mode == 3:
                result.append(modes[mode])

            mode = (mode + 1)%4
            idx_sup = idx_inf
            if mode == 0:
                idx_inf -= 1
            else:
                idx_inf -= 2

        result.append(' '*(4-len(str(i))) + str(i) + '.')

        print(' '.join(reversed(result)))

    except EOFError:

        break