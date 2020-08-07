from typing import List
from collections import Counter
import re


class Solution:
    def mostCommonWord(self, paragraph: str, banned: List[str]) -> str:
        count = Counter(re.sub(r'[^\w]', ' ', paragraph.lower()).split())
        ban_set = set(banned)

        # return next(k for k in Counter.most_common(count) if not k[0][0] in ban_set)
        while True:
            most = Counter.most_common(count)[0][0]
            if most in ban_set:
                count.pop(most)
            else:
                return most
