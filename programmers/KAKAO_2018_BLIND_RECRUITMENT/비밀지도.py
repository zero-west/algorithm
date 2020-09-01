def solution(n, arr1, arr2):
    answer = [str() for _ in range(n)]

    fir = [bin(i)[2:].rjust(n, '0') for i in arr1]
    sec = [bin(i)[2:].rjust(n, '0') for i in arr2]

    for i in range(n):
        for j in range(n):
            if fir[i][j] == '1' or sec[i][j] == '1':
                answer[i] += '#'
            else:
                answer[i] += ' '
    return answer
