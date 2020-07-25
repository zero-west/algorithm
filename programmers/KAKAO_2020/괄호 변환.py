import sys
from collections import Counter

sys.setrecursionlimit(10 ** 7)


def solution(p):
    if len(p) == 0:
        return ''

    for idx, ch in enumerate(p):
        u_count = Counter(p[:idx + 1])
        v_count = Counter(p[idx + 1:])

        if u_count['('] == u_count[')'] and v_count['('] == v_count[')']:
            stack = []
            for bracket in p[:idx + 1]:
                if not stack:
                    stack.append(bracket)
                else:
                    if bracket == ')' and stack[-1] == '(':
                        stack.pop()
                    else:
                        stack.append(bracket)
            if not stack:
                answer = p[:idx + 1] + solution(p[idx + 1:])
                return answer
            else:
                answer = '(' + solution(p[idx + 1:]) + ')'
                for k in p[:idx + 1][1:-1]:
                    if k == ')':
                        answer += '('
                    else:
                        answer += ')'
                return answer
