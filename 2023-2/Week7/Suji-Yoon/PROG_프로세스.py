from collections import deque
import heapq

def solution(priorities, location):
    answer = 0
    l = len(priorities)
    queue = deque([i for i in range(l)])
    hq = []

    for i in range(l):
        heapq.heappush(hq, -priorities[i])

    cnt = 0
    while queue:
        n = queue.popleft()
        if priorities[n] != -hq[0]:
            queue.append(n)
        else:
            cnt += 1
            heapq.heappop(hq)
            if (n == location):
                return cnt
            
    return answer
