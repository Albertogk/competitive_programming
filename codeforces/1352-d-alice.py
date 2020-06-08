
t = int(input())

for i in range(t):
    n = int(input())
    candies = list(map(int, input().split()))
    idx_a = 0
    idx_b = n-1
    turn = True # True es Alice, False Bob
    objective = 0
    current = 0
    moves = 0
    a = 0
    b = 0
    while idx_a <= idx_b:
        if turn:
            current += candies[idx_a]
            a += candies[idx_a]
            idx_a += 1

        else:
            current += candies[idx_b]
            b += candies[idx_b]
            idx_b -= 1

        if current > objective or idx_a > idx_b:
            moves += 1
            objective = current
            current = 0
            turn = not turn

    print(moves, a, b)
