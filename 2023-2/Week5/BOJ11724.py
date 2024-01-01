import sys 
sys.setrecursionlimit(10**7)

# 10^24라는 무지막지한...시간복잡도...
# N,M = map(int, sys.stdin.readline().split(" "))
# graph = []
# visited = [False for i in range(M)]
# count = 0 

# for i in range (M) : 
#     start, end = map(int, sys.stdin.readline().split(" "))
#     graph.append([start,end])

# def dfs(start) : 
#     visited[start] = True
    
#     for index in range(M) : 
#         if not visited[index] and graph[index][0] == graph[start][1] :
#             dfs(index)

# for i in range(M) : 
#     if not visited[i] :
#         dfs(i)
#         count += 1

# print(count)


N,M = map(int, sys.stdin.readline().split(" "))
graph = [[] for i in range(N+1)]
visited = [False for i in range(N+1)]
        
for i in range (M) : 
    start, end = map(int, sys.stdin.readline().split(" "))
    graph[start].append(end)
    graph[end].append(start)
    
def dfs(v) : 
    visited[v] = True
    for i in graph[v] :
        if visited[i] == False : 
            dfs(i)

count = 0 

for i in range(1, N+1) : 
    if not visited[i] :
        dfs(i)
        count += 1
        
print(count)