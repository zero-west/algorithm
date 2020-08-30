dR = [-1, 0, 1, 0]
dC = [0, -1, 0, 1]


def get_dist(cur, nxt):
    return abs(cur[0] - nxt[0]) + abs(cur[1] - nxt[1])


def solution(numbers, hand):
    answer = ''
    mapping = [(3, 1), (0, 0), (0, 1), (0, 2), (1, 0), (1, 1), (1, 2), (2, 0), (2, 1), (2, 2)]

    leftIdx = (3, 0)
    rightIdx = (3, 2)

    for i in range(len(numbers)):
        if numbers[i] == 1 or numbers[i] == 4 or numbers[i] == 7:
            answer += 'L'
            leftIdx = mapping[numbers[i]]
        elif numbers[i] == 3 or numbers[i] == 6 or numbers[i] == 9:
            answer += 'R'
            rightIdx = mapping[numbers[i]]
        else:
            a = get_dist(leftIdx, mapping[numbers[i]])
            b = get_dist(rightIdx, mapping[numbers[i]])

            if a == b:
                if hand == 'left':
                    answer += 'L'
                    leftIdx = mapping[numbers[i]]
                else:
                    answer += 'R'
                    rightIdx = mapping[numbers[i]]
            elif a > b:
                answer += 'R'
                rightIdx = mapping[numbers[i]]
            else:
                answer += 'L'
                leftIdx = mapping[numbers[i]]
    return answer
