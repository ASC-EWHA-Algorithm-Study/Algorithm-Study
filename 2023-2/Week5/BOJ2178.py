import sys
from collections import deque

"""
def dfs(graph, visited, x,y, answer) : 
    visited[y][x] = True
    answer = answer +1
    
    if x == M and y == N : 
        print(answer)
    
    for i in range(4) : 
        if 0<= y + dy[i] < N and 0< x + dx[i] <=M : 
            if not visited[y + dy[i]][x + dx[i]] and graph[y + dy[i]][x + dx[i]] == 1: 
                dfs(graph, visited, x + dx[i], y + dy[i], answer)
"""

def bfs(graph, visited, x, y) :
    q = deque()
    q.append((x,y))
    visited[y][x] =1
    
    while q : 
        x,y = q.popleft()
        
        for i in range(4) : 
            nx, ny = x + dx[i], y+ dy[i]
            if 0 <= nx < M and 0<= ny < N : 
                if visited[ny][nx] == 0  and graph[ny][nx] == 1: 
                    visited[ny][nx] = visited[y][x] + 1
                    q.append((nx, ny))
    
    return visited[N-1][M-1]
            

if __name__ == "__main__" : 
    N,M = map(int, sys.stdin.readline().split(" "))
    graph = []
    visited = [[0 for i in range(101)] for j in range(101)]
    
    for i in range(N) : 
        numbers = [int(char) for char in sys.stdin.readline().strip()]
        graph.append(numbers)
    
    dx = [-1,1,0,0]
    dy = [0,0,-1,1]
    print(bfs(graph, visited, 0,0))
        
    