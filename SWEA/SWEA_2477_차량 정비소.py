from collections import deque
import bisect


def binary_search(seq, val):
    index = bisect.bisect_left(seq, val)
    return index < len(seq) and val == seq[index]


T = int(input())

for tc in range(1, T + 1):
    N, M, K, A, B = map(int, input().split())

    receipt = list(map(int, input().split()))
    maintain = list(map(int, input().split()))
    arrive = list(map(int, input().split()))

    tcRes = 0

    rQueue = deque([])
    mQueue = deque([])
    rCounter = [None] * N
    mCounter = [None] * M

    cnt = 0
    for time in range(50000):
        if cnt == K:
            break

        for i in range(M):
            if mCounter[i] is None:
                continue

            if time - mCounter[i][1] == maintain[i]:
                cnt += 1
                if mCounter[i][0][1] == A - 1 and i == B - 1:
                    tcRes += (mCounter[i][0][0] + 1)
                mCounter[i] = None

        for i in range(N):
            if rCounter[i] is None:
                continue

            if time - rCounter[i][1] == receipt[i]:
                mQueue.append((rCounter[i][0], i))  # (고객번호, 접수방문정보)
                rCounter[i] = None

        for i in range(M):
            if mCounter[i] is None and mQueue:
                curInfo = mQueue.popleft()
                mCounter[i] = (curInfo, time)  # ((고객번호, 접수방문정보), 정비 들어간 시간)
            elif not mQueue:
                break

        for i in range(N):
            if rCounter[i] is None and rQueue:
                curIdx = rQueue.popleft()
                rCounter[i] = (curIdx, time)  # (고객번호, 접수 들어간 시간)
            elif not rQueue:
                break

        if binary_search(arrive, time):
            lo_idx = bisect.bisect_left(arrive, time)
            hi_idx = bisect.bisect_right(arrive, time)

            for idx in range(lo_idx, hi_idx):
                rQueue.append(idx)  # 고객번호

    print('#%d %d' % (tc, tcRes if tcRes != 0 else -1))
