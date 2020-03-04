# 리스트가 주어졌을 때 전부 섞는 모든 경우의 수 (= std::next_permutation())
def all_perms(arr):
    if len(arr) <= 1:
        yield arr
    else:
        for nxt in all_perms(arr[1:]):
            for i in range(len(arr)):
                # nb elements[0:1] works in both string and list contexts
                yield nxt[:i] + arr[0:1] + nxt[i:]

                

# 리스트에서 r 개 뽑아 섞는 경우의 수 (= 순열)
r = 3
arr = [1,2,3,4,5]
def permutations(prefix,k):
    if len(prefix) == r:
        yield prefix
    else:
        for i in range(k, len(arr)):
            arr[i], arr[k] = arr[k], arr[i]
            for nxt in permutations(prefix + [arr[k]], k + 1):
                yield nxt
            arr[i], arr[k] = arr[k], arr[i]
           
permutations([],0)        # 제너레이터 호출



# 리스트에서 r 개 뽑는 경우의 수 (= 조합)
def combi(arr, r):
    for i in range(len(arr)):
        if r == 1:
            yield [arr[i]]
        else:
            for nxt in combi(arr[i + 1:], r - 1):
                yield [arr[i]] + nxt

                
# 리스트에서 r개 중복을 허용하여 뽑는 경우의 수 (= 중복조합)
def combi_rep(arr, r):
    for i in range(len(arr)):
        if r == 1:
            yield [arr[i]]
        else:
            for nxt in combi(arr[i:], r-1):
                yield [arr[i]] + nxt
                
                
                
# 리스트 각각의 원소에 대해 선택여부 : O(2^N) (= 멱집합)
def powerset(arr):
    masking = [1 << i for i in range(len(arr))]

    for i in range(1 << len(arr)):
        yield [a for a, mask in zip(arr, masking) if mask & i]
                
                
