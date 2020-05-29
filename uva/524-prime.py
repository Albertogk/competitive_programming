import math

def is_prime(n):

    for i in range(2, int(math.sqrt(n)) + 1):
        if n % i == 0:
            return False

    return True

def solve(n, path, last_val, is_path):
    result = []
    for i in range(2, n+1):
        if is_path[i-1] == 1:
            continue

        value = i+last_val
        if is_prime(value):
            if len(path) == n-1:
                if is_prime(i+1):
                    return [path + [str(i)]]

            else:
                is_path[i-1] = 1
                result += solve(n, path+[str(i)], i, is_path)
                is_path[i-1] = 0


    return result


if __name__ == '__main__':
    i = 1
    while 1:
        try:

            n = int(input())
            is_path = [0]*n
            is_path[0] = 1
            lists = solve(n, ['1'], 1, is_path)
            print("Case " + str(i) + ":")
            for l in lists:
                print(' '.join(l))
            print()
            i = i + 1

        except EOFError:
            break