
def create_tree(n, tracks, sum, node_path):
    i=0
    max_value = sum
    final_path = node_path
    for t in tracks:
        i += 1
        value = t + sum
        if value > n:
            continue

        value_aux, path = create_tree(n, tracks[i:], value, node_path + [str(t)])
        if value_aux > max_value:
            max_value = value_aux
            final_path = path

    return max_value, final_path


if __name__ == '__main__':

    while 1:
        try:

            aux = list(map(lambda x: int(x), input().split()))
            n = aux[0]
            tracks = aux[2:]
            max_value, nodes = create_tree(n, tracks, 0, [])
            print(' '.join(nodes), "sum:" + str(max_value))

        except EOFError:
            break
