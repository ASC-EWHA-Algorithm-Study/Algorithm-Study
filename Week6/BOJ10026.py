import sys 
sys.setrecursionlimit(10**7)

N = int(sys.stdin.readline())
colors=[]

dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]
visited = [[False for i in range(N)] for i in range(N)]

for i in range(N) : 
    arr = [char for char in sys.stdin.readline().strip()]
    colors.append(arr)

count = 0 
special_count = 0

def dfs(y, x, color) : 
    visited[y][x] = True
    
    for i in range(4) : 
        nx, ny = x + dx[i], y + dy[i]
        if 0<=nx<N and 0<=ny<N and visited[ny][nx] == False and colors[ny][nx] == color :
            dfs(ny, nx, color)

def special_dfs(y, x, color) : 
    visited[y][x] = True
    
    for i in range(4) : 
        nx, ny = x + dx[i], y + dy[i]
        if 0<=nx<N and 0<=ny<N and visited[ny][nx] == False :
            if (color == 'R' and (colors[ny][nx] == color or colors[ny][nx] == 'G')) or (color == 'G' and (colors[ny][nx] == color or colors[ny][nx] == 'R')) or (color == 'B' and colors[ny][nx] == color)  :  
                colors[ny][nx] == color
                special_dfs(ny, nx, color)
    
for i in range(N) : 
    for j in range(N) :
        if visited[i][j] == False :
            color = colors[i][j]
            dfs(i, j, color)
            count += 1
print(count)

visited = [[False for i in range(N)] for i in range(N)]
for i in range(N) : 
    for j in range(N) :
        if visited[i][j] == False :
            color = colors[i][j]
            special_dfs(i, j, color)
            special_count += 1
            
print(special_count)
    