from typing import List


class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        if len(nums) < 3:
            return []

        answer = set()
        nums.sort()
        dic = {}
        for idx, num in enumerate(nums):
            if num in dic:
                dic[num].append(idx)
            else:
                dic[num] = [idx]

        for idx, num in enumerate(nums):
            if idx != 0 and nums[idx - 1] == nums[idx]:
                continue

            for jdx in range(idx + 1, len(nums)):
                if jdx != idx + 1 and nums[jdx - 1] == nums[jdx]:
                    continue
                if -(num + nums[jdx]) in dic:
                    for k in dic[-(num + nums[jdx])]:
                        if k != idx and k != jdx:
                            answer.add(tuple(sorted((nums[idx], nums[jdx], nums[k]))))
                            break
        return [list(k) for k in answer]

    def threeSum2(self, nums: List[int]) -> List[List[int]]:
        answer = []
        nums.sort()

        for idx in range(len(nums) - 2):
            if idx > 0 and nums[idx] == nums[idx - 1]:
                continue

            left, right = idx + 1, len(nums) - 1

            while left < right:
                cur_sum = nums[idx] + nums[left] + nums[right]

                if cur_sum < 0:
                    left += 1
                elif cur_sum > 0:
                    right -= 1
                else:
                    answer.append((nums[idx], nums[left], nums[right]))

                    while left < right and nums[left] == nums[left + 1]:
                        left += 1
                    while left < right and nums[right] == nums[right - 1]:
                        right -= 1

                    left += 1
                    right -= 1
        return answer
