import itertools

def solution(k, dungeons):
    answer = 0
    orders = list(itertools.permutations(dungeons))
    for order in orders:
        cur = k
        cnt = 0
        for minimum, cost in order:
            if (minimum <= cur):
                cur -= cost
                cnt += 1
        answer = max(answer, cnt)
    return answer
