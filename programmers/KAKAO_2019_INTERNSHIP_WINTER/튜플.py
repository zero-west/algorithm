# def solution2(s):
#     cur_list = []
#     tot_list = []
#     stack = []
#     for ch in s[1:-1]:
#         try:
#             int(ch)
#             stack.append(ch)
#         except:
#             cur_num = ''.join(stack)
#             if cur_num:
#                 cur_list.append(int(cur_num))
#             if ch == '}':
#                 tot_list.append(list(cur_list))
#                 cur_list.clear()
#             stack.clear()
#
#     tot_list.sort(key=lambda k: len(k))
#     answer = []
#     ret_set = set()
#     for li in tot_list:
#         for num in li:
#             if not num in ret_set:
#                 ret_set.add(num)
#                 answer.append(num)
#                 break
#     return answer


from collections import Counter

def solution(s):
    answer = []
    return [int(k) for k, v in
            Counter(s.translate(str.maketrans("{}", "  ")).replace(' ', '').split(',')).most_common()]

