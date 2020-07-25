import sys
from collections import Counter

sys.setrecursionlimit(10 ** 7)


def solution(p):
    if len(p) == 0:
        return ''

    for idx, ch in enumerate(p):
        u = p[:idx+1]
        v = p[idx+1:]
        u_count = Counter(u)
        v_count = Counter(v)

        if u_count['('] == u_count[')'] and v_count['('] == v_count[')']:
            stack = []
            for bracket in u:
                if not stack:
                    stack.append(bracket)
                else:
                    if bracket == ')' and stack[-1] == '(':
                        stack.pop()
                    else:
                        stack.append(bracket)
            if not stack:
                answer = u + solution(v)
                return answer
            else:
                answer = '(' + solution(v) + ')'
                for k in u[1:-1]:
                    if k == ')':
                        answer += '('
                    else:
                        answer += ')'
                return answer
