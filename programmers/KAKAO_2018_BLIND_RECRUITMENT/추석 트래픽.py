def solution(lines):
    section_list = []

    for line in lines:
        time_info = line[11:line.rfind(' ')].split(':')
        second_info = time_info[2].split('.')
        end_time = 3600000 * int(time_info[0]) + 60000 * int(time_info[1]) \
                   + int(second_info[0]) * 1000 + int(second_info[1])

        required_info = line[line.rfind(' '):-1].split('.')
        required_time = int(required_info[0]) * 1000
        try:
            required_time += int(required_info[1][0]) * 100
            required_time += int(required_info[1][1]) * 10
            required_time += int(required_info[1][2])
        except IndexError:
            pass

        start_time = end_time - required_time + 1
        section_list.append((start_time, end_time))

    answer = 0
    for info in section_list:
        cnt = 0
        for section in section_list:
            if section[1] < info[1] or section[0] > info[1] + 999:
                continue
            cnt += 1
        answer = max(answer, cnt)
    return answer
