import sys
import itertools
import copy
input = sys.stdin.readline

dx = [1, -1, 0, 0]
dy = [0, 0, 1, -1]

def dfs(i, j, visit, arr):
    st = [(i,j)]
    while st:
        x, y = st.pop()
        for k in range(4):
            xx = x + dx[k]
            yy = y + dy[k]
            if (xx >= 0 and xx < N and yy >= 0 and yy < M):
                if (arr[xx][yy] == 0 and visit[xx][yy] == False):
                    visit[xx][yy] = True
                    arr[xx][yy] = 2
                    st.append((xx,yy))

def get_safe(arr, virus):
    visit = [[False] * M for _ in range(N)]
    for i, j in virus:
        dfs(i,j, visit, arr)
    cnt = 0
    for i in range(N):
        for j in range(M):
            if (arr[i][j] == 0):
                cnt += 1
    return cnt
        

N, M = map(int, input().split())    
arr = []
for _ in range(N):
    arr.append(list(map(int, input().split())))

virus = []
for i in range(N):
        for j in range(M):
            if (arr[i][j] == 2):
                virus.append((i,j))
                
points = list(itertools.combinations([(x, y) for x in range(N) for y in range(M)], 3))
answer = 0
for a, b, c in points:
    if (arr[a[0]][a[1]] == 0 and arr[b[0]][b[1]] == 0 and arr[c[0]][c[1]] == 0):
        walls = copy.deepcopy(arr)
        walls[a[0]][a[1]] = 1
        walls[b[0]][b[1]] = 1
        walls[c[0]][c[1]] = 1
        answer = max(answer, get_safe(walls, virus))
print(answer)
        
            
