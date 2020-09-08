def solution(msg):
    answer = []
    mapping = {chr(i): i - 64 for i in range(65, 91)}
    val = 27
    idx, nIdx = 0, 1
    while nIdx <= len(msg):
        nIdx = idx + 1
        while nIdx <= len(msg) and msg[idx:nIdx] in mapping:
            nIdx += 1
        else:
            answer.append(mapping[msg[idx:nIdx - 1]])
            mapping[msg[idx:nIdx]] = val
            val += 1
        idx = nIdx - 1
    return answer
