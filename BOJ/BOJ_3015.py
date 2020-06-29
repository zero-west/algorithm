import sys
from collections import deque

if __name__ == '__main__':
    N = int(sys.stdin.readline())
    result = 0

    people = [int(sys.stdin.readline()) for _ in range(N)]
    stack = deque([])

    for human in people:
        if not stack:
            stack.append((human, 1))
        else:
            if stack[-1][0] == human:
                if len(stack) >= 2:
                    result += 1
                result += stack[-1][1]
                stack[-1] = (human, stack[-1][1] + 1)
            elif stack[-1][0] < human:
                while stack and stack[-1][0] < human:
                    result += stack[-1][1]
                    stack.pop()

                if not stack:
                    stack.append((human, 1))
                    continue

                if stack[-1][0] == human:
                    result += stack[-1][1]
                    stack[-1] = (human, stack[-1][1] + 1)

                    if len(stack) >= 2:
                        result += 1
                else:
                    result += 1
                    stack.append((human, 1))
            else:
                result += 1
                stack.append((human, 1))

    print(result)
