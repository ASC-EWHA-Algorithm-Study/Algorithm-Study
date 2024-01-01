import sys
from collections import deque

def solution(graph, start, visited) : 
    queue = deque([start])
    
    visited[start] = True
    cnt = 0 
    
    while queue : 
        v = queue.popleft()
        cnt += 1
        for i in graph[v] : 
            if not visited[i] : 
                queue.append(i)
                # 큐에 넣고 나서 방문 처리해줘야함!
                visited[i] = True
    
    return cnt - 1

if __name__ == "__main__" : 
    cnt_pc = int(sys.stdin.readline())
    
    cnt_connect = int(sys.stdin.readline())
    
    # graph = [[]] * (cnt_pc + 1)
    # 이 코드는 리스트 내에 동일한 하위 리스트에 대한 참조를 복사하기 때문에 문제가 발생합니다. 
    # 따라서 하위 리스트를 공유하게 됩니다.
    
    graph = [[] for _ in range(cnt_pc +1)] 
    visited = [False for _ in range(cnt_pc +1)]
    
    for _ in range(cnt_connect) : 
        N, M = map(int, sys.stdin.readline().split(" "))
        
        graph[N].append(M)
        graph[M].append(N)
        
    for i in graph : 
        i.sort()
    
    print(solution(graph, 1, visited))
    
        