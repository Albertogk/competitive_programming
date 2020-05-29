import math
def calculate_points(floor, eliminated, r, c):
    result = 0
    for i in range(0, r):
        for j in range(0, c):
            if eliminated[i][j] == 0:
                result += floor[i][j]

    return result

def solve(floor, r, c):
    eliminated = []
    result = 0
    north = None
    north_flag = 0
    south = None
    south_flag = 0
    west = None
    west_flag = 0
    east = None
    east_flag = 0
    end = 0
    for i in range(0, r):
        row = []
        for j in range(0, c):
            row.append(0)

        eliminated.append(row)

    while end == 0:
        end = 1
        new_res = calculate_points(floor, eliminated, r, c)

        if new_res == 0:
            break
        result += new_res
        elim_round = []
        for i in range(0, r):
            row = []
            for j in range(0, c):
                row.append(0)

            elim_round.append(row)

        for i in range(0, r):
            for j in range(0, c):
                if eliminated[i][j] == 1:
                    continue
                mean = 0
                north_flag = 0
                south_flag = 0
                west_flag = 0
                east_flag = 0
                idx = 1
                cnt = 0
                if j-idx >= 0:
                    while eliminated[i][j-idx] == 1:
                        idx += 1
                        if j-idx < 0:
                            west_flag = 1
                            break
                else:
                    west_flag = 1

                if west_flag == 0:
                    cnt += 1
                    mean += floor[i][j-idx]

                idx = 1
                if j + idx < c:
                    while eliminated[i][j + idx] == 1:
                        idx += 1
                        if j + idx >= c:
                            east_flag = 1
                            break
                else:
                    east_flag = 1

                if east_flag == 0:
                    cnt += 1
                    mean += floor[i][j+idx]

                idx = 1
                if i + idx < r:
                    while eliminated[i+ idx][j] == 1:
                        idx += 1
                        if j + idx >= r:
                            south_flag = 1
                            break
                else:
                    south_flag = 1

                if south_flag == 0:
                    cnt += 1
                    mean += floor[i+idx][j]


                idx = 1
                if i - idx >= 0:
                    while eliminated[i - idx][j] == 1:
                        idx += 1
                        if j - idx < 0:
                            north_flag = 1
                            break
                else:
                    north_flag = 1

                if north_flag == 0:
                    cnt += 1
                    mean += floor[i - idx][j]


                if cnt > 0:
                    mean = mean/cnt

                    if floor[i][j] < int(math.ceil(mean)):
                        end = 0
                        elim_round[i][j] = 1

        for i in range(0, r):
            for j in range(0, c):
                if elim_round[i][j] == 1:
                    eliminated[i][j] = 1

    return result


if __name__ == '__main__':
    t = int(input())
    for i in range(0, t):
        l = input().split()
        r = int(l[0])
        c = int(l[1])
        floor = []
        for j in range(0, r):
            floor.append(list(map(lambda x: int(x), input().split())))

        print("Case #" + str(i+1) + ": " +  str(solve(floor, r, c)))
