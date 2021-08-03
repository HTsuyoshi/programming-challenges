import array

while True:
    linha = input()

    if linha == '.':
        break

    palavras = linha.split(" ")
    palavrasOrdenadas = sorted(palavras)

    auxiliar = []
    auxiliarFreq = []
    i = -1
    for x in palavrasOrdenadas:
        if x == '':
            continue
        if x not in auxiliar:
            auxiliar.append(x)
            auxiliarFreq.append(1)
            i += 1
        else:
            auxiliarFreq[i] += 1

    freq = [] 
    substituir = []
    for x in range(26):
        freq.append(0)
        substituir.append("")

    for x in range(len(auxiliar)):
        size = (len(auxiliar[x]) - 2) * auxiliarFreq[x]
        index = ord(auxiliar[x][0]) - 97
        if size > freq[index] and size > 0:
            freq[index] = size
            substituir[index] = auxiliar[x]

    for x in range(len(palavras)):
        if palavras[x] == '':
            continue
        if palavras[x] == substituir[ord(palavras[x][0]) - 97]:
            print(palavras[x][0] + ".", end="")
        else:
            print(palavras[x], end="")
        if x != len(palavras) - 1:
            print(" ", end="")
    print()

    i = 0
    for x in substituir:
        if x != "":
            i += 1

    print(i)

    for x in substituir:
        if x == "":
            continue
        print(x[0] + ". = " + x)

