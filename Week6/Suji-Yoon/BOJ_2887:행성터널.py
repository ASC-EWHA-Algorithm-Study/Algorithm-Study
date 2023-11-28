import sys
import itertools
input = sys.stdin.readline

def find_parent(x, parent):
    if (parent[x] != x):
        parent[x] = find_parent(parent[x], parent)
    return parent[x]
    
def union(a, b, parent):
    a = find_parent(a, parent)
    b = find_parent(b, parent)
    if (a < b):
        parent[b] = a
    else:
        parent[a] = b

N = int(input())
x = []
y = []
z = []
for i in range(N):
    a, b, c = map(int, input().split())
    x.append((a, i))
    y.append((b, i))
    z.append((c, i))
    
x.sort()
y.sort()
z.sort()

edges = []
parent = [i for i in range(N)]

## 여기가 포인트!!
for i in range(N-1):
    edges.append((x[i+1][0] - x[i][0], x[i+1][1], x[i][1]))
    edges.append((y[i+1][0] - y[i][0], y[i+1][1], y[i][1]))
    edges.append((z[i+1][0] - z[i][0], z[i+1][1], z[i][1]))
  
edges.sort()
ans = 0
for cost, a, b in edges:
    if (find_parent(a, parent) != find_parent(b, parent)):
        union(a, b, parent)
        ans += cost
        
print(ans)
        
