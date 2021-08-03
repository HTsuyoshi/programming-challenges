import sys
sys.setrecursionlimit(50000)

linha = input().split(" ")
W = int(linha[0])
H = int(linha[1])

matrix = [[]]
passou = [[]]
comeco = [0,0]

for x in range(H):
    linha = input()
    for y in linha:
        matrix[x].append(y)
    matrix.append([])

for x in range(H):
    for y in range(W):
        passou[x].append(0)
    passou.append([])

def andar(matrix, passou, i, H, W):

    if(passou[i[0]][i[1]] == 1):
        return
    else:
        passou[i[0]][i[1]] = 1

    if i[0] < 0 or i[0] > H:
        return
    if i[1] < 0 or i[1] > W:
        return

    if matrix[i[0]][i[1]] in '#T':
        return

    if matrix[i[0]+1][i[1]] == 'T' or matrix[i[0]][i[1]+1] == 'T' or matrix[i[0]-1][i[1]] == 'T' or matrix[i[0]][i[1]-1] == 'T':
        passou[i[0]][i[1]] = 1
        return

    passou[i[0]][i[1]] = 1

    andar(matrix, passou, [i[0]+1,i[1]], H, W)
    andar(matrix, passou, [i[0],i[1]+1], H, W)
    andar(matrix, passou, [i[0]-1,i[1]], H, W)
    andar(matrix, passou, [i[0],i[1]-1], H, W)

def arrumarmapa(char):
    if char in "#TP":
        return 1
    else:
        return 0

for x in range(H):
    for y in range(W):
        if matrix[x][y] == 'P':
            comeco[0], comeco[1] = x, y
        passou[x].append(arrumarmapa(matrix[x][y]))
    passou.append([])

andar(matrix, passou, comeco, H, W)

ouro = 0

for x in range(H):
    for y in range(W):
        if passou[x][y] == 1 and matrix[x][y] == 'G':
            ouro += 1

print(ouro)


