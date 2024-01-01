import sys
from collections import deque
input = sys.stdin.readline

N, L, R = map(int, input().split())
arr = []
for _ in range(N):
    arr.append(list(map(int, input().split())))
    
# 인구 차이가 L <= x <= R일때
# 1. 국경이 열리는지 판단
# 2. 인구이동

dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]

def bfs(arr, x, y, visit):
    q = deque()
    q.append((x,y))
    visit[x][y] = True
    total = 0
    cnt = 0
    union = []
    while q:
        x, y = q.popleft()
        total += arr[x][y]
        union.append((x,y))
        cnt += 1
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if (nx >= 0 and nx < N and ny >= 0 and ny < N and visit[nx][ny] == False):
                diff = abs(arr[nx][ny] - arr[x][y])
                if (diff >= L and diff <= R):
                    q.append((nx, ny))
                    visit[nx][ny] = True
    return total, cnt, union

ans = 0
while True:
    visit = [[False] * N for _ in range(N)]
    flag = False
    for i in range(N):
        for j in range(N):
            if (visit[i][j] == False):
                total, cnt, union = bfs(arr, i, j, visit)
                if (cnt > 1):
                    after = total // cnt
                    for x, y in union:
                        arr[x][y] = after
                    flag = True
    if (flag == False):
        break
    ans += 1
print(ans)
        
        
        
