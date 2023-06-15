from typing import List


def fullJustify(words: List[str], max_width: int) -> List[str]:
    curr_len, space = 0, 0
    curr, t = [], []
    for word in words:
        if curr_len + space + len(word) <= max_width:
            curr_len += len(word)
            curr.append(word)
            space += 1
        else:
            t.append((curr, curr_len))
            curr_len = len(word)
            curr = [word]
            space = 1
    if curr: 
        t.append((curr, curr_len))

    res = []
    del curr
    for words, cnt in t[:-1]:
        n = len(words)-1
        words = iter(words)
        curr = [next(words)]
        space = max_width - cnt
        if n > 0:
            q, r = space // n, space % n
            for word in words:
                if r > 0: curr.append(' ')
                curr += (' ')*q
                curr.append(word)
                r = max(r-1, 0)
        else:
            curr += (' ')*space
        res.append(''.join(curr))

    last_words, last_cnt = t[-1]
    space = max_width - last_cnt
    space_left = space - len(last_words) + 1
    res.append(' '.join(last_words) + ' '*space_left)

    return res