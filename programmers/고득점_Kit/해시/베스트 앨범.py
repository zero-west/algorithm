def solution(genres, plays):
    answer = []

    counter = {genre: 0 for genre in genres}
    li = {genre: [] for genre in genres}
    for idx, play in enumerate(plays):
        counter[genres[idx]] += play
        li[genres[idx]].append((play, idx))

    rank = sorted(counter, key=lambda k: counter[k], reverse=True)
    for genre in rank:
        answer.extend(i[1] for i in sorted(li[genre], key=lambda k: (k[0], -k[1]), reverse=True)[:2])

    return answer
