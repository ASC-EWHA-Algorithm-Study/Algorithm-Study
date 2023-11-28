import math
from collections import deque

def solution(progresses, speeds):
    q = deque()
    answer = []
    for i in range(len(progresses)):
        q.append(math.ceil((100 - progresses[i]) / speeds[i]))
    
    while q:
        cnt = 1
        cur = q.popleft()
        while (q and q[0] <= cur):
            cnt += 1
            q.popleft()
        answer.append(cnt)
    return answer
