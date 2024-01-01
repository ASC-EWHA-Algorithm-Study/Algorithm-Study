import sys
from collections import deque

T = int(sys.stdin.readline())

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]

def bfs(x, y):
  queue = deque()
  queue.append((x,y))

  while queue:
    x, y = queue.popleft()
    for i in range(4):
      nx = x + dx[i]
      ny = y + dy[i]

      if nx < 0 or ny < 0 or nx >=N or ny >= M:
        continue

      if matrix[nx][ny] == 1:
        queue.append((nx,ny))
        matrix[nx][ny] = 0

  return

for _ in range(T):
  M, N, K = map(int, sys.stdin.readline().split())
  matrix = [[0]*M for _ in range(N)]

  for i in range(K):
    x, y = map(int, sys.stdin.readline().split())
    matrix[y][x] = 1

  cnt = 0
  for i in range(N):
    for j in range(M):
      if matrix[i][j] ==1:
        bfs(i, j)
        cnt +=1

  print(cnt)

# def solution(graph,i,j,visited): 
#     queue = deque([graph[i][j]])
    
#     visited[i][j] = True
#     cnt = 0
    
#     while queue : 
#         v = queue.popleft()
#         for t, index in graph[i] : 
#             if(t == 1 and not visited[i][index]) : 
#                 v.append(t)
#                 visited[i][index] = True
#         cnt += 1

# if __name__ == "__main__" : 
#     T = int(input())
    
#     for _ in range(T) : 
#         M, N, K = map(int, input().split(" "))
        
#         graph = [[0 for i in range(N)] for i in range(M)]
#         visited = [[False for i in range(N)] for i in range(M)]
        
#         for _ in range(K) : 
#             i, j = map(int,input().split(" "))
#             graph[i][j] = 1
            
#         solution(graph,0,0,visited)