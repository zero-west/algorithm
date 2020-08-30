import sys

fir = sys.stdin.readline().rstrip()
sec = sys.stdin.readline().rstrip()

dp = [[0] * (len(sec) + 2) for _ in range(len(fir) + 2)]

ret = 0
res = str()
for idx in range(1, len(fir) + 1):
    for jdx in range(1, len(sec) + 1):
        if fir[idx-1] == sec[jdx-1]:
            dp[idx][jdx] = dp[idx - 1][jdx - 1] + 1
            ret = max(ret, dp[idx][jdx])

print(ret)
