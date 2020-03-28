import sys
sys.setrecursionlimit(10**8)

def getParent(parent, cur):
    if parent[cur] == cur:
        return cur
    parent[cur] = getParent(parent, parent[cur])
    return parent[cur]

def unionParent(parent, a, b):
    x = getParent(parent, a)
    y = getParent(parent, b)

    if x <= y:
        parent[x] = y
    else:
        parent[y] = x

def solution(k, room_number):
    parent = {}
    answer = []
    for wanted in room_number:
        if wanted not in parent:
            answer.append(wanted)
            parent[wanted] = wanted + 1

            if wanted + 1 in parent:
                unionParent(parent, wanted, wanted + 1)
            else:
                parent[wanted + 1] = wanted + 1
        else:
            curAns = getParent(parent, wanted)
            answer.append(curAns)

            if curAns + 1 in parent:
                unionParent(parent, wanted, curAns + 1)
            else:
                parent[curAns + 1] = curAns + 1
                unionParent(parent, wanted, curAns+1)

    return answer
