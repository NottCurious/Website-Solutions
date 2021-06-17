g = [[int(t) for t in s.split()] for s in open('pe11.txt').readlines()]

mxP = 0
rows = len(g)
cols = len(g[0])
pSize = 4

for i in range(rows):
    for j in range(cols - pSize  +  1):
        phv = max(g[i][j] * g[i][j + 1] * g[i][j + 2] * g[i][j + 3],
                  g[j][i] * g[j + 1][i] * g[j + 2][i] * g[j + 3][i])
        if i <= rows-pSize:
           pdd = max(g[i][j] * g[i + 1][j + 1] * g[i + 2][j + 2] * g[i + 3][j + 3],
                     g[i][j + 3] * g[i + 1][j + 2] * g[i + 2][j + 1] * g[i + 3][j])
        mxP = max(mxP, phv, pdd)
print(mxP)
