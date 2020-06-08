n = int(input())

mural = input()

result = 'Yes'
flag = True
if mural.count('?') == 0:
    print('No')

else:
    if n == 1 or n == 2:
        print('Yes')

    else:
        flag2 = False
        for i in range(1, n-1):
            if mural[i] == mural[i-1] or mural[i] == mural[i+1]:
                if mural[i] != '?':
                    result = 'No'
                    flag2 = True
                    break
                else:
                    result = 'Yes'
                    flag = False

            elif mural[i] == '?' and flag:
                if mural[i-1] != mural[i+1]:
                    result = 'No'
                else:
                    result = 'Yes'
                    flag = False

        if not flag2 and (mural[0] == '?' or mural[-1] == '?'):
            print('Yes')
        else:
            print(result)