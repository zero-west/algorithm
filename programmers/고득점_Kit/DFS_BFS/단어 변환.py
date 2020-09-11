def solution(begin, target, words):
    words = set(words)
    if target not in words or len(begin) != len(target):
        return 0

    global answer, visited
    answer, visited = float('inf'), set()

    def dfs(cur, depth):
        global answer, visited
        if cur == target:
            answer = min(answer, depth)
            return

        for idx, ch in enumerate(cur):
            for code in range(97, 123):
                nxt = cur[:idx] + chr(code) + cur[idx + 1:]

                if nxt in words and nxt not in visited:
                    visited.add(nxt)
                    dfs(cur[:idx] + chr(code) + cur[idx + 1:], depth + 1)
                    visited.remove(nxt)

    visited.add(begin)
    dfs(begin, 0)
    return answer
