import sys
from collections import deque

N, M = map(int, sys.stdin.readline().split(" "))
graph = []

for i in range(N) : 
    numbers = [int(char) for char in sys.stdin.readline().strip()]
    graph.append(numbers)

dx = [-1,1,0,0]
dy =[0,0,-1,1]

visited = [[0 for i in range(M)] for i in range(N)]

def bfs(x,y) : 
    q = deque()
    q.append([x,y])
    visited[y][x] = 1
    
    while q : 
        nx, ny = q.popleft()
        
        if nx == M -1 and ny == N -1 : 
            break
        
        for i in range(4) : 
            px, py = nx + dx[i], ny + dy[i]
            if 0<=px<M and 0<=py<N and visited[py][px] == 0 and graph[py][px] == 1 : 
                q.append([px,py])
                visited[py][px] = visited[ny][nx] + 1
                
    print(visited[N-1][M-1])
                
bfs(0,0)
