import sys
from collections import deque
input = sys.stdin.readline

N = int(input())
K = int(input())
arr = [[0] * N for _ in range(N)]
for _ in range(K):
    a, b = map(int, input().split())
    arr[a-1][b-1] = 1
L = int(input())

dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]
direction = 0
time = 0
isOver = False
q = deque()
q.append((0,0))
change = deque()

for _ in range(L):
    X, C = input().split()
    change.append((int(X), C))
    
while (True):
    if (len(change) != 0 and time == change[0][0]):
        if (change[0][1] == 'L'):
            direction = (direction - 1) % 4
        else:
            direction = (direction + 1) % 4 
        change.popleft()
    # print(time, direction, q)
    x, y = q[-1]
    nx = x + dx[direction]
    ny = y + dy[direction]
    if (nx < 0 or nx >= N or ny < 0 or ny >= N):
        print(time + 1)
        break
    if ((nx, ny) in q):
        print(time + 1)
        break
    if (arr[nx][ny] != 0):
        arr[nx][ny] = 0
        q.append((nx, ny))
    else:
        q.popleft()
        q.append((nx, ny))
    time += 1
