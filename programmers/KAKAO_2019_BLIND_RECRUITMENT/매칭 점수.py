def solution(word, pages):
    url_to_idx = {}
    cnt_list = [[] for _ in range(len(pages))]

    basic = [0] * len(pages)
    tot_out = [0] * len(pages)
    for idx, page in enumerate(pages):
        cur_idx = 0
        while True:
            cur_idx = page.lower().find(word.lower(), cur_idx + 1)
            if cur_idx == -1:
                break
            if page[cur_idx - 1].isalpha() or page[cur_idx + len(word)].isalpha():
                continue
            basic[idx] += 1

        url_flag = '<meta property="og:url" content="'
        url_to_idx[page[page.find(url_flag) + len(url_flag):page.find('"', page.find(url_flag) + len(url_flag))]] = idx

    for idx, page in enumerate(pages):
        cur_idx = 0
        while True:
            link_flag = '<a href="'
            cur_idx = page.find(link_flag, cur_idx + 1)
            if cur_idx == -1:
                break
            tot_out[idx] += 1

            out_link = page[cur_idx + len(link_flag):page.find('"', cur_idx + len(link_flag))]
            if out_link in url_to_idx:
                cnt_list[url_to_idx[out_link]].append(idx)

    matching = []
    for idx in range(len(pages)):
        link_score = 0
        for linked in cnt_list[idx]:
            link_score += basic[linked] / tot_out[linked]
        matching.append(float(basic[idx])+link_score)

    return matching.index(max(matching))
