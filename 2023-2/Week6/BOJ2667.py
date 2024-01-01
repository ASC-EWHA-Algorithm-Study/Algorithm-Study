import sys

N = int(sys.stdin.readline())
village = []
visited = [[False for i in range(N)] for i in range(N)]

dx = [-1, 1, 0, 0]
dy = [0, 0, 1, -1]
ans = []
count = 0 

for i in range(N) : 
    numbers = [int(char) for char in sys.stdin.readline().strip()]
    village.append(numbers)

def dfs(y,x) : 
    visited[y][x] = True
    global count 
    count += 1
    
    for i in range(4) : 
        ny, nx = y + dy[i], x+ dx[i]
        if 0<=ny<N and 0<=nx<N and visited[ny][nx] == False and village[ny][nx] == 1: 
            dfs(ny,nx)    


for i in range(N) : 
    for j in range(N) : 
        if visited[i][j] == False and village[i][j] == 1: 
            dfs(i,j)
            ans.append(count) 
            count = 0 

ans.sort()
print(len(ans))
for i in ans : 
    print(i)