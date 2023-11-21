import sys 
sys.setrecursionlimit(10000)

T = int(sys.stdin.readline())

dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

# recursion error? 

def dfs(x,y,M,N, visited,graph) : 
    visited[y][x] = True
    
    for i in range(4) :
        nx, ny = x + dx[i], y + dy[i]
        if 0<=nx<M and 0<=ny<N :
            if  visited[ny][nx] == False and graph[ny][nx] == 1 :
                dfs(nx,ny,M,N, visited,graph)

def solution() : 
    count = 0
    M,N,K = map(int,sys.stdin.readline().split(" "))

    graph = [[0 for i in range(M)] for j in range(N)]
    visited = [[False for i in range(M)] for j in range(N)]

    for i in range(K) : 
        x,y = map(int,sys.stdin.readline().split(" "))
        graph[y][x] = 1
     
    for i in range(N) :
        for j in range(M) :  
            if visited[i][j] == False and graph[i][j] == 1 :
                dfs(j,i,M,N, visited,graph)  
                count += 1
        
    print(count)
    
for i in range(T) : 
    solution()