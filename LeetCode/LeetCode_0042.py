from typing import List


class Solution:
    # Stack
    def trap(self, height: List[int]) -> int:
        try:
            first = next((num, idx) for idx, num in enumerate(height) if num != 0)
        except StopIteration:
            return 0

        answer = 0
        stack = [first[0]]
        for h in height[first[1] + 1:]:
            if not stack:
                stack.append(h)
            else:
                if h <= stack[-1]:
                    stack.append(h)
                else:
                    if h >= stack[0]:
                        while stack and stack[-1] <= stack[0]:
                            answer += stack[0] - stack[-1]
                            stack.pop()
                    else:
                        for idx in range(len(stack) - 1, 0, -1):
                            if stack[idx] < h:
                                answer += h - stack[idx]
                                stack[idx] = h
                            else:
                                break
                    stack.append(h)
        return answer

    # Two Pointer
    def trap2(self, height: List[int]) -> int:
        try:
            info = next((num, idx) for idx, num in enumerate(height))
            left, right = info[1], len(height) - 1
        except StopIteration:
            return 0

        answer = 0
        max_left, max_right = height[left], height[right]

        while left < right:
            max_left, max_right = max(max_left, height[left]), max(max_right, height[right])
            if max_left <= max_right:
                answer += max_left - height[left]
                left += 1
            else:
                answer += max_right - height[right]
                right -= 1
        return answer
