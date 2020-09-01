def solution(dartResult):
    nums, infos, answers = [], [], [0, 0, 0, 0]

    for i in range(len(dartResult) - 1):
        if dartResult[i:i + 2].isdigit():
            nums.append(int(dartResult[i:i + 2]))
        elif dartResult[i + 1] == '*' or dartResult[i + 1] == '#':
            infos.append(dartResult[i:i + 2])
        elif dartResult[i].isalpha():
            infos.append(dartResult[i].ljust(2, '-'))
        elif dartResult[i].isdigit() and not dartResult[i-1].isdigit():
            nums.append(int(dartResult[i]))
    if len(infos) == 2:
        infos.append(dartResult[-1].ljust(2, '-'))

    for i in range(3):
        if infos[i][0] == 'S':
            answers[i + 1] = nums[i]
        elif infos[i][0] == 'D':
            answers[i + 1] = nums[i] ** 2
        elif infos[i][0] == 'T':
            answers[i + 1] = nums[i] ** 3

        if infos[i][1] == '*':
            answers[i] *= 2
            answers[i + 1] *= 2
        elif infos[i][1] == '#':
            answers[i + 1] *= -1
    return sum(answers[1:])
