def solution(s):
    cnt_x = 0 
    cnt_other = 0
    x = 0
    idx = 0
    answer = 0
    while idx < len(s):
        if (s[x] != s[idx]):
            cnt_other += 1
        else:
            cnt_x += 1
        if (cnt_x == cnt_other):
            answer += 1
            x = idx + 1
            cnt_x = 0
            cnt_other = 0
        idx += 1
    if (cnt_x != cnt_other): answer += 1
    return answer
