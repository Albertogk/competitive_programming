t = int(input())

for i in range(t):
    string = list(input())
    if len(string) < 3:
        print(0)
    else:
        zeros = 0
        ones = 0
        min_changes = 2000
        zeros_total = string.count('0')
        ones_total = len(string)-zeros_total
        for i in range(len(string)):
            if string[i] == '0':
                zeros += 1
            else:
                ones += 1

            changes = min(ones+zeros_total-zeros, zeros+ones_total-ones)
            if changes < min_changes:
                min_changes = changes

        print(min_changes)