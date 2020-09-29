from typing import List


class Solution:
    def maxArea(self, height: List[int]) -> int:
        N = len(height)
        i, j, result = 0, N - 1, 0
        while i < j:
            result = max(result, min(height[i], height[j]) * (j - i))
            if height[i] >= height[j]:
                j -= 1
            else:
                i += 1
        return result
