T = int(input())

dr = [0, 0, -1, 1]
dc = [1, -1, 0, 0]

for tc in range(1, T + 1):
    N = int(input())
    info = [list(map(int, input().split())) for _ in range(N)]

    for k in info:
        k[0] *= 2
        k[1] *= 2

    visited = [0] * (N+1)
    tcRes = 0
    time = 0

    while True:
        if time == 4001:
            break

        nxtList = {}
        cnt = 0
        for idx in range(N):
            if visited[idx] == 1:
               cnt += 1
               continue

            curR, curC, Dir, Energy = info[idx]
            nR = curR + dr[Dir]
            nC = curC + dc[Dir]
            
            info[idx][0] = nR
            info[idx][1] = nC
            
            if (nR, nC) in nxtList:
                preEnergy, visIdx = nxtList[(nR,nC)]
                preEnergy += Energy
                visited[visIdx] = 1
                visited[idx] = 1

                # 갱신
                nxtList[(nR,nC)] = (preEnergy, N)
            else:
                nxtList[(nR, nC)] = (Energy, idx)

        for nxt in nxtList.keys():
            if nxtList[nxt][1] == N:
                tcRes += nxtList[nxt][0]

        if cnt == N:
            break
        else:
            time += 1

    print('#%d %d' % (tc, tcRes))
