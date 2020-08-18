import re

# 단어 문자가 아닌 모든 문자를 공백으로 치환
paragraph = "Bob hit a ball, the hit BALL flew far after it was hit"
banned = ["hit"]
words = [word for word in re.sub(r'[^\w]', '', paragraph).lower().split() if word not in banned]
