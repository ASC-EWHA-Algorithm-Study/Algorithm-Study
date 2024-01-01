from collections import deque

def solution(queue1, queue2):
    queue1 = deque(queue1)
    queue2 = deque(queue2)
    n1 = sum(queue1)
    n2 = sum(queue2)
    n = n1 + n2
    if (n % 2 != 0): return -1
    n = n // 2

    # 더 큰쪽이 더 작은쪽에게 pop&insert 
    answer = 0
    while (len(queue1) > 0 and len(queue2) > 0):
        if (n1 == n2):
            return answer
        
        if (n1 > n2):
            q1 = queue1.popleft()
            queue2.append(q1)
            n1 -= q1
            n2 += q1
            answer += 1
            
        if (n1 < n2):
            q2 = queue2.popleft()
            queue1.append(q2)
            n2 -= q2
            n1 += q2
            answer += 1

        # 11, 28 시간초과
        if (answer > 10**6):
            return -1

    return -1
