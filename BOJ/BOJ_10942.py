import sys

N = int(sys.stdin.readline())
seq = list(map(int, sys.stdin.readline().split()))
M = int(sys.stdin.readline())

cache = {}

for _ in range(M):
    S, E = map(int, sys.stdin.readline().split())

    if (S, E) in cache:
        print(cache[(S, E)])
    else:
        if S - 2 != -1:
            if seq[S - 1:E] == seq[E - 1:S - 2:-1]:
                cache[(S, E)] = 1
                print(1)
            else:
                cache[(S, E)] = 0
                print(0)
        else:
            if seq[S - 1:E] == seq[E - 1::-1]:
                cache[(S, E)] = 1
                print(1)
            else:
                cache[(S, E)] = 0
                print(0)
