def solution(files):
    info = [None for _ in range(len(files))]
    for idx, file in enumerate(files):
        num_start, tail_start = None, None
        for jdx, ch in enumerate(file):
            try:
                int(ch)
                num_start = jdx
                break
            except ValueError:
                pass

        for i in range(num_start, min(num_start + 5, len(file))):
            if not file[i].isdecimal():
                tail_start = i
                break
        if not tail_start:
            tail_start = num_start + 5
        info[idx] = (file[:num_start].lower(), int(file[num_start:tail_start]), idx)
    info.sort()

    return [files[k[2]] for k in info]
