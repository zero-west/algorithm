import sys

sys.setrecursionlimit(10 ** 7)

# 술병 갯수, 서랍갯수
N, L = map(int, sys.stdin.readline().split())

info = [tuple(map(int, sys.stdin.readline().split())) for _ in range(N)]
parent = [i for i in range(L + 1)]
check = [True] + [False for _ in range(L)]


def getParent(x):
    if parent[x] == x:
        return x
    else:
        parent[x] = getParent(parent[x])
        return parent[x]


def unionParent(x, y):
    X, Y = getParent(x), getParent(y)

    if X != Y:
        parent[X] = Y


for curInfo in info:
    if not check[curInfo[0]]:
        unionParent(curInfo[0], curInfo[1])
        check[curInfo[0]] = True
        print("LADICA")
    elif not check[curInfo[1]]:
        check[curInfo[1]] = True
        unionParent(curInfo[1], curInfo[0])
        print("LADICA")
    elif not check[getParent(curInfo[0])]:
        curIdx = getParent(curInfo[0])
        check[curIdx] = True
        unionParent(curInfo[0], curInfo[1])
        print("LADICA")
    elif not check[getParent(curInfo[1])]:
        curIdx = getParent(curInfo[1])
        check[curIdx] = True
        unionParent(curInfo[1], curInfo[0])
        print("LADICA")
    else:
        print("SMECE")
