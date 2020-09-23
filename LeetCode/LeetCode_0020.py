class Solution:
    def isValid(self, s: str) -> bool:
        mapping = {'(': ')', '{': '}', '[': ']'}
        stack = []

        for ch in s:
            if ch in mapping or not stack:
                stack.append(ch)
            else:
                try:
                    if mapping[stack[-1]] == ch:
                        stack.pop()
                    else:
                        return False
                except KeyError:
                    return False

        return True if not stack else False
