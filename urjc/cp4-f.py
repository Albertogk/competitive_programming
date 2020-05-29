def contagiar(contagios, contactos, n):
    for ele in contactos[n]:
        if contagios[ele] == 0:
            contagios[ele] = 1
            contagiar(contagios, contactos, ele)


n, m = list(map(lambda x: int(x), input().split()))
contagios = [0]*n
contactos = {}

if n > 0:
    for i in range(0, m):
        l = input().split()
        if l[0] == 'CONTACTO':
            a = int(l[1])
            b = int(l[2])
            if a not in contactos:
                contactos[a] = []

            contactos[a].append(b)

            if b not in contactos:
                contactos[b] = []

            contactos[b].append(a)

            if contagios[a] == 1:
                if contagios[b] == 0:
                    contagios[b] = 1
                    contagiar(contagios, contactos, b)

            elif contagios[b] == 1:
                contagios[a] = 1
                contagiar(contagios, contactos, a)

        elif l[0] == 'POSITIVO':
            a = int(l[1])
            contagios[a] = 1
            contagiar(contagios, contactos, a)

        else:
            a = int(l[1])
            if contagios[a] == 1:
                print("POSIBLE")
            else:
                print("NO")