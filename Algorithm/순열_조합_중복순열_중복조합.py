# 리스트가 주어졌을 때 모든 경우의 수 (= std::next_permutation())
def all_perms(arr):
    if len(arr) <= 1:
        yield arr
    else:
        for nxt in all_perms(arr[1:]):
            for i in range(len(arr)):
                # nb elements[0:1] works in both string and list contexts
                yield nxt[:i] + arr[0:1] + nxt[i:]


# 리스트에서 r 개 뽑는 경우의 수 (= 조합)
def combinations(arr, r):
    for i in range(len(arr)):
        if r == 1:
            yield [arr[i]]
        else:
            for nxt in combinations(arr[i+1:], r-1):
                yield [arr[i]] + nxt

