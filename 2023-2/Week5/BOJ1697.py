import sys
from collections import deque

""""
def bfs(start, dest, visited, ans) : 
    queue = deque([])
    visited[start] = True
    queue.append(start)
    
    while queue : 
        print(queue)
        v = queue.popleft()
        if v == dest :
            dist.append(ans)
            ans = 0
            continue
        
        for i in range(3) : 
            if i == 0 : 
                dx = 2*v
                print(dx)
            elif i == 1 : 
                dx = v + 1 
            else : 
                dx = v -1 
                
            if dx < 0 or dx > dest : 
                    continue
            if visited[dx] == False : 
                visited[dx] = True
                ans += 1 
                bfs(ans, )

    
    return min(dist),dist
"""

dist = [0] * 100001
def bfs(N,K) :
    q = deque()
    q.append(N)
    
    while q : 
        x = q.popleft()
        if x == K : 
            print(dist[x])
            break
        # 위에 내가 쓴 것처럼 조건문으로 저렇게 안나누고 이렇게 쓸 수 있구나!
        for nx in (x-1, x+1, x *2) : 
            # 방문을 안했을 경우에만 값을 갱신해야함!
            # 큐에 이미 방문했다면 이미 최단 경로로 거기까지 온거니까 다시 갱신할 일이 없음!
            if 0 <= nx <= 100000 and dist[nx] == False: 
                dist[nx] = dist[x] + 1
                q.append(nx)

if __name__ == "__main__" : 
        N, K = map(int, sys.stdin.readline().split(" "))
        bfs(N,K)