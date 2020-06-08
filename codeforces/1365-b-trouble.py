if __name__ == '__main__':
    t = int(input())
    for i in range(t):
        n = int(input())
        arr = list(map(int, input().split()))
        type = list(map(int, input().split()))

        zeros = type.count(0)
        if zeros == 0 or zeros == n:
            flag = True
            for i in range(n-1):
                if arr[i] > arr[i+1]:
                    print("No")
                    flag = False
                    break

            if flag:
                print("Yes")
        else:
            print("Yes")