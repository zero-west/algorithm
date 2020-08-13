from typing import List


class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        length = len(nums)

        left = [1] + [0] * (length - 1)
        right = [0] * (length - 1) + [1]

        for idx in range(len(nums) - 1):
            left[idx + 1] = left[idx] * nums[idx]

        for idx in range(len(nums) - 1, 0, -1):
            right[idx-1] = right[idx - len(nums)] * nums[idx]

        return [left[i] * right[i] for i in range(len(nums))]
