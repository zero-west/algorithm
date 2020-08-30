def solution(record):
    answer = []
    infos = [k.split() for k in record]
    mapping = {}

    for info in infos:
        if info[0] == 'Enter':
            mapping[info[1]] = info[2]
        elif info[0] == 'Change':
            mapping[info[1]] = info[2]

    for info in infos:
        if info[0] == 'Enter':
            answer.append(mapping[info[1]] + '님이 들어왔습니다.')
        elif info[0] == 'Leave':
            answer.append(mapping[info[1]] + '님이 나갔습니다.')

    return answer
