import sys 
from collections import deque

MAX = 100000
N, K = map(int, sys.stdin.readline().split(' '))
dist = [0 for i in range(MAX +1)]

def bfs() : 
    q = deque()
    q.append(N)
    
    while q : 
        x = q.popleft()
        if x == K : 
            break
        for position in [x+1, x-1, 2*x] : 
            if 0<=position<=MAX and not dist[position]: 
                dist[position] += dist[x] + 1
                q.append(position)

bfs()
print(dist[K])