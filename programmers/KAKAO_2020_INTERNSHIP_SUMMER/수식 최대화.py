from itertools import permutations


def solution(expression):
    answer = 0
    nums = []
    operators = []
    num = ''

    for ch in expression:
        try:
            int(ch)
            num += ch
        except ValueError:
            nums.append(int(num))
            operators.append(ch)
            num = ''
    nums.append(int(num))

    for priority in permutations(set(operators)):
        tmp_nums = list(nums)

        for op in priority:
            for operIdx in range(len(operators)):
                cur_operator = operators[operIdx]

                if op == cur_operator:
                    lIdx = operIdx
                    rIdx = operIdx

                    while tmp_nums[lIdx] is None:
                        lIdx -= 1
                    while tmp_nums[rIdx + 1] is None:
                        rIdx += 1

                    if cur_operator == '+':
                        tmp_nums[lIdx] = tmp_nums[lIdx] + tmp_nums[rIdx + 1]
                    elif cur_operator == '-':
                        tmp_nums[lIdx] = tmp_nums[lIdx] - tmp_nums[rIdx + 1]
                    elif cur_operator == '*':
                        tmp_nums[lIdx] = tmp_nums[lIdx] * tmp_nums[rIdx + 1]

                    tmp_nums[rIdx + 1] = None
        answer = max(answer, abs(tmp_nums[0]))
    return answer
