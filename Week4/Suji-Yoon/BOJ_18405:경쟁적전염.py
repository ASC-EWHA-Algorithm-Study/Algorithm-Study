import sys
from collections import deque
input = sys.stdin.readline

N, K = map(int, input().split())
arr = []
for _ in range(N):
    arr.append(list(map(int, input().split())))
S, X, Y = map(int, input().split())

q = deque()
visit = [[False] * N for _ in range(N)]

# 시작 바이러스 위치
for i in range(N):
    for j in range(N):
        if (arr[i][j] != 0):
            q.append((i, j, arr[i][j]))
            visit[i][j] = True

dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]
for s in range(S):
    qq = deque()
    while q:
        x, y, virus = q.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if (nx >= 0 and nx < N and ny >= 0 and ny < N):
                if (visit[nx][ny] == False and (arr[nx][ny] == 0 or arr[nx][ny] > virus)):
                    arr[nx][ny] = virus
                    qq.append((nx, ny, virus))
    q = qq
    for x, y, v in q:
        visit[x][y] = True
print(arr[X-1][Y-1])
    
