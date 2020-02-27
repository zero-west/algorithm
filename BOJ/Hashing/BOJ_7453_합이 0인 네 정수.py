N = int(input())
A = [None] * N
B = [None] * N
C = [None] * N
D = [None] * N

result = 0
mp1 = {}
mp2 = {}

for i in range(N):
    A[i], B[i], C[i], D[i] = map(int, input().split())

for i in range(N):
    for j in range(N):
        if A[i] + B[j] in mp1:
            mp1[A[i] + B[j]] += 1
        else:
            mp1[A[i] + B[j]] = 1

        if C[i] + D[j] in mp2:
            mp2[C[i] + D[j]] += 1
        else:
            mp2[C[i] + D[j]] = 1

for k in mp2:
    if -1 * k in mp1:
        result += mp2[k] * mp1[-1 * k]

print(result)
