def solution(citations):
    answer = 0
    citations.sort()
    n = len(citations)

    for h in range(n, 0, -1):
        citate = citations[n-h]
        if (citate >= h):
            return h
    return 0
