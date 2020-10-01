from typing import List


class Solution:
    def dailyTemperatures(self, T: List[int]) -> List[int]:
        res = [0] * len(T)
        stack = []
        for idx, cur in enumerate(T):
            if not stack:
                stack.append((idx, cur))
            else:
                while stack and stack[-1][1] < cur:
                    res[stack[-1][0]] = idx - stack[-1][0]
                    stack.pop()
                stack.append((idx, cur))
        return res
