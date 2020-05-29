def solve(s, d, value, last_four, n_rec):

    if n_rec > 11:
        return value

    max_value = -1

    if n_rec >= 4:
        four_month_value = sum(last_four)
        five_month_value_s = four_month_value + s

        if five_month_value_s < 0:

            value2 = solve(s, d, value+s, last_four[1:] + [s], n_rec+1)
            max_value = value2
            value2 = solve(s, d, value-d, last_four[1:] + [-d], n_rec + 1)
            max_value = max(max_value, value2)

        elif four_month_value - d < 0:

            value2 = solve(s, d, value - d, last_four[1:] + [-d], n_rec + 1)
            max_value = value2


    else:
        value2 = solve(s, d, value+s, last_four +[s], n_rec+1)
        max_value = value2
        value2 = solve(s, d, value - d, last_four + [-d], n_rec + 1)
        max_value = max(max_value, value2)

    return max_value


if __name__ == '__main__':

    while 1:
        try:

            aux = list(map(lambda x: int(x), input().split()))
            s = aux[0]
            d = aux[1]
            max_value = solve(s, d, 0, [], 0)
            if max_value < 0:
                print('Deficit')
            else:
                print(max_value)

        except EOFError:
            break
