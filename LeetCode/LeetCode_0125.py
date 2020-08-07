from collections import deque
import re


class Solution:
    def isPalindrome(self, s: str) -> bool:
        s = deque([ch.lower() for ch in s if ch.isalnum()])

        while len(s) > 1:
            if s.popleft() != s.pop():
                return False
        return True

    def isPalindrome2(self, s: str) -> bool:
        s = s.lower()
        s = re.sub('[^a-z0-9]', '', s)

        return s == s[::-1]

