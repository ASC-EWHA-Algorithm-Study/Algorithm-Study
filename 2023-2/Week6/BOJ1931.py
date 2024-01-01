import sys 

N = int(sys.stdin.readline())
graph = []

for i in range(N) : 
    x, y = map(int, sys.stdin.readline().split(" "))
    graph.append([x,y])

graph = sorted(graph, key = lambda x : (x[1],x[0]))

end = graph[0][1]
count = 1
for i in range(1, N) : 
    if graph[i][0] >= end : 
        end = graph[i][1]
        count += 1
        
print(count)