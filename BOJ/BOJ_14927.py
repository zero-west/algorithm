N = int(input())

dr = [-1, 0, 1, 0]
dc = [0, -1, 0, 1]


def powerset(arr):
    masking = [1 << i for i in range(len(arr))]

    for i in range(1 << len(arr)):
        yield [a for a, mask in zip(arr, masking) if mask & i]


def change(arr, R, C):
    global N

    arr[R][C] ^= 1

    for k in range(4):
        nR = R + dr[k]
        nC = C + dc[k]

        if nR < 0 or nC < 0 or nR >= N or nC >= N:
            continue

        arr[nR][nC] ^= 1


board = [list(map(int, input().split())) for _ in range(N)]
li = [i for i in range(N)]

result = float('inf')


for totSet in powerset(li):
    cnt = 0
    cnt += len(totSet)

    curBoard = []
    for k in board:
        curBoard.append(list(k))

    if totSet:
        for i in totSet:
            change(curBoard, 0, i)

    for i in range(1, N):
        for j in range(0, N):
            if curBoard[i - 1][j] == 1:
                change(curBoard, i, j)
                cnt += 1

    flag = True
    for i in range(N):
        if curBoard[N - 1][i] == 1:
            flag = False

    if flag:
        result = min(result, cnt)

if result == float('inf'):
    print(-1)
else:
    print(int(result))
