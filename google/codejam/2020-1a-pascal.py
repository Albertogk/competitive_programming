
import operator as op
from functools import reduce

def calculate_combinatory(n, r):
    r = min(r, n-r)
    numer = reduce(op.mul, range(n, n-r, -1), 1)
    denom = reduce(op.mul, range(1, r+1), 1)
    return numer / denom

def solve(n, path, value, r, c, n_iter):
    result = []
    if n_iter > 500:
        return None
    n_iter += 1
    if value == n:
        return path


    if c > 1:
        if [str(r), str(c-1)] not in path:
            new_value = value + calculate_combinatory(r - 1, c-2)
            if new_value <= n:
                result = solve(n, path + [[str(r), str(c-1)]], new_value, r, c-1, n_iter)
                if result:
                    return result

        if r > 1:
            if [str(r-1), str(c-1)] not in path:
                new_value = value + calculate_combinatory(r-2, c-2)
                if new_value <= n:
                    result = solve(n, path + [[str(r-1), str(c-1)]], new_value, r-1, c-1, n_iter)
                    if result:
                        return result

    if c < r:
        if [str(r), str(c+1)] not in path:
            new_value = value + calculate_combinatory(r-1, c)
            if new_value <= n:
                result = solve(n, path + [[str(r), str(c+1)]], new_value, r, c+1, n_iter)
                if result:
                    return result

        if r > 1:
            if [str(r-1), str(c)] not in path:
                new_value = value + calculate_combinatory(r-2, c - 1)
                if new_value <= n:
                    result = solve(n, path + [[str(r-1), str(c)]], new_value, r -1, c, n_iter)
                    if result:
                        return result

    if [str(r+1), str(c)] not in path:
        new_value = value + calculate_combinatory(r, c-1)
        if new_value <= n:
            result = solve(n, path + [[str(r+1), str(c)]], new_value, r+1, c, n_iter)
            if result:
                return result

    if [str(r+1), str(c+1)] not in path:
        new_value = value + calculate_combinatory(r, c)
        if new_value <= n:
            result = solve(n, path + [[str(r+1), str(c+1)]], new_value, r+1, c+1, n_iter)
            if result:
                return result




    return result


if __name__ == '__main__':
    t = int(input())
    for i in range(0, t):
        n = int(input())
        lists = solve(n, [['1', '1']], 1, 1, 1, 1)
        print("Case #" + str(i+1) + ":")
        for l in lists:
            print(' '.join(l))