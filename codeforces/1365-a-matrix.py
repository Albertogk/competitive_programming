def fill_ones(matrix, row, col, n, m):
    for k in range(0, n):
        if k != row and matrix[k][col] == 0:
            matrix[k][col] = 2

    for k in range(0, m):
        if k != col and matrix[row][k] == 0:
            matrix[row][k] = 2

t = int(input())

for x in range(t):
    matrix = []

    n, m = list(map(int, input().split()))

    for j in range(n):
        matrix.append(list(map(int, input().split())))

    for i in range(n):
        for j in range(m):
            if matrix[i][j] == 1:
                fill_ones(matrix, i, j, n, m)

    moves = 0
    for i in range(n):
        for j in range(m):
            if matrix[i][j] == 0:
                matrix[i][j] = 1
                fill_ones(matrix, i, j, n, m)
                moves += 1

    if moves % 2 == 0:
        print('Vivek')
    else:
        print('Ashish')


