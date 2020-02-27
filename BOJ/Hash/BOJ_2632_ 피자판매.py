import bisect

select = int(input())
m, n = map(int, input().split())

AList = [None] * 2 * m
BList = [None] * 2 * n

pSumA = [None] * 2 * m
pSumB = [None] * 2 * n

result = 0
sumset = {}

for i in range(m):
    AList[i] = int(input())
    AList[i + m] = AList[i]

for i in range(n):
    BList[i] = int(input())
    BList[i + n] = BList[i]

for i in range(0, 2 * m):
    pSumA[i] = (AList[0] if i == 0 else pSumA[i - 1] + AList[i])

for i in range(0, 2 * n):
    pSumB[i] = (BList[0] if i == 0 else pSumB[i - 1] + BList[i])

totA = int(sum(AList) / 2)
totB = int(sum(BList) / 2)

for i in range(m):
    for j in range(i, i + m - 1):
        flag = (pSumA[j] if i == 0 else pSumA[j] - pSumA[i - 1])

        if flag == select:
            result += 1

        if flag in sumset:
            sumset[flag] += 1
        else:
            sumset[flag] = 1

        if flag + totB == select:
            result += 1

for i in range(n):
    for j in range(i, i + n - 1):
        flag = (pSumB[j] if i == 0 else pSumB[j] - pSumB[i - 1])

        if flag == select:
            result += 1

        if select - flag in sumset:
            result += sumset[select - flag]

        if select - flag == totA:
            result += 1

if totA == select:
    result += 1
if totB == select:
    result += 1
if totA + totB == select:
    result += 1

print(result)
