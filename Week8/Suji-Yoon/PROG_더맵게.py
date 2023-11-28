import heapq

def solution(scoville, K):
    answer = 0
    hq = []
    for s in scoville:
        heapq.heappush(hq, s)
    low_sco = hq[0]
    
    while (low_sco < K):
        if (len(hq) < 2):
            return -1
        a = heapq.heappop(hq)
        b = heapq.heappop(hq)
        new = a + b*2
        heapq.heappush(hq, new)
        low_sco = hq[0]
        answer += 1
    return answer
