from typing import List


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        mapping = {num: idx for idx, num in enumerate(nums)}

        for idx, num in enumerate(nums):
            if target - num in mapping and idx != mapping[target - num]:
                return sorted([idx, mapping[target - num]])

    def twoSum2(self, nums: List[int], target: int) -> List[int]:
        p, q = 0, len(nums) - 1
        new_list = sorted([(num, idx) for idx, num in enumerate(nums)])

        while p < q:
            if new_list[p][0] + new_list[q][0] > target:
                q -= 1
            elif new_list[p][0] + new_list[q][0] < target:
                p += 1
            else:
                return sorted([new_list[p][1], new_list[q][1]])
