import sys
from collections import deque

sys.setrecursionlimit(10 ** 7)

# 정점 갯수, 쿼리 갯수
N, Q = map(int, sys.stdin.readline().split())

origin = [0, 1] + [int(sys.stdin.readline()) for _ in range(N - 1)]
parent = [i for i in range(N + 1)]

query = [tuple(map(int, sys.stdin.readline().split())) for _ in range(N + Q - 1)]


def getParent(x):
    if parent[x] == x:
        return x
    else:
        parent[x] = getParent(parent[x])
        return parent[x]


def unionParent(x, y):
    a, b = getParent(x), getParent(y)

    if a != b:
        parent[a] = b


result = deque([])
for curQ in query[::-1]:
    if curQ[0] == 0:
        unionParent(curQ[1], origin[curQ[1]])
    else:
        if getParent(curQ[1]) == getParent(curQ[2]):
            result.appendleft("YES")
        else:
            result.appendleft("NO")

print('\n'.join(result))
