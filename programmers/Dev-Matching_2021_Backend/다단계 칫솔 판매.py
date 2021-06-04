def solution(enroll, referral, seller, amount):
    head = {e: r if r != '-' else 'center' for e, r in zip(enroll, referral)}
    cnt = {e: 0 for e in enroll + ['center']}

    def solve(cur, cur_amount):
        cnt[cur] += cur_amount - cur_amount // 10

        if cur_amount * 9 // 10 >= 1 and cur in head:
            solve(head[cur], cur_amount // 10)

    for s, a in zip(seller, amount):
        solve(s, a * 100)

    return [cnt[e] for e in enroll]
