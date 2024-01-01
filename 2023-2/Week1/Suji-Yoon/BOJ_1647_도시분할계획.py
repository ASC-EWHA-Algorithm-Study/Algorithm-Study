import sys
input = sys.stdin.readline

N, M = map(int, input().split())
parents = [i for i in range(N+1)]

def find_parent(x, parents):
    if (parents[x] != x):
        parents[x] = find_parent(parents[x], parents)
    return parents[x]
    
def union(a, b, parents):
    a = find_parent(a, parents)
    b = find_parent(b, parents)
    if (a < b): parents[b] = a
    else: parents[a] = b
    
edges = []
for _ in range(M):
    a, b, c = map(int, input().split())
    edges.append([a, b, c])
edges.sort(key = lambda x : x[2])

answer = 0
max_c = 0
for a, b, c in edges:
    if (find_parent(a, parents) != find_parent(b, parents)):
        union(a, b, parents)
        max_c = max(max_c, c)
        answer += c
print(answer - max_c)
    
