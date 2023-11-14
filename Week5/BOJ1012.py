import sys 
from collections import deque

T = int(sys.stdin.readline())

dx = [1,0,-1,0]
dy = [0,-1,0,1]

def bfs(x,y) : 
    queue = deque()
    queue.append((x,y))
    visited[x][y] = True
    
    while queue : 
        x, y = queue.popleft()
        for i in range(4) : 
            # 위, 아래 , 양, 옆 모두 탐색 
            nx, ny = x + dx[i] , y + dy[i]
            # 왜 nx는 가로인데 N보다 크면 빠꾸?
            if nx < 0 or nx >= N or ny < 0 or ny >=M : 
                continue
            if farm[nx][ny] and not visited[nx][ny] : 
                queue.append((nx,ny))
                visited[nx][ny] = True
                

for i in range(T) : 
    M,N,K = map(int, sys.stdin.readline().split(" "))

    farm= [[0 for i in range(M)] for j in range(N)]
    visited = [[False for i in range(M)] for j in range(N)]

    # 문제에 나와있는 배추가 심어져있는 위치를 표시하는 부분 
    for i in range(K) : 
        # 왜 y, x 반대로지?
        y, x = map(int, sys.stdin.readline().split(" "))
        farm[x][y] = 1
        
    result = 0 
    # 반복문을 돌면서 1인데 visited안된 부분에서 bfs 돌려서 묶음 찾아내기 
    for i in range(N) : 
        for j in range(M) : 
            if farm[i][j] and not visited[i][j] :
                bfs(i,j) 
                result += 1
    print(result)


