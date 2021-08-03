import sys

linhas = sys.stdin.read().strip().split('\n')
for l in range (len (linhas) // 3):
    n = int (linhas [l*3])
    saida = []
    for x in linhas [l*3 + 1].split (" "):
        saida.append (int (x) - 1)
    chegada = []
    for x in linhas [l*3 + 2].split (" "):
        chegada.append ([[int(x) - 1], [0]])

    output = 0
    ordemSaida = []
    for x in range(n):
        ordemSaida.append(0)
    for x in range(n):
        ordemSaida[saida[x]] = x

    i = 0
    j = 0
    while i < n:
        j = 0
        chegada[i][1] = 1
        while j < n:
            aux = chegada[i][0]
            aux1 = chegada[j][0]
            comparou = chegada[j][1]
            if comparou == 1:
                j += 1
                continue
            if ordemSaida[aux[0]] > ordemSaida[aux1[0]]:
                output += 1
            j += 1
        i += 1

    print(output)

