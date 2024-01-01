import sys
import itertools
input = sys.stdin.readline

N = int(input())
arr = []
teacher = []
x = []

for i in range(N):
    arr.append(list(input().split()))
    for j in range(N):
        if (arr[i][j] == 'T'):
            teacher.append((i,j))
        elif (arr[i][j] == 'X'):
            x.append((i,j))
    
dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]
obstacle = list(itertools.combinations(x, 3))

# 3개의 장애물 설치해서 모든 학생을 감시에서 피하도록
# YES or No

# 완전 탐색
def check(arr, teacher):
    for i, j in teacher:
        # 상
        nx, ny = i, j
        for ny in range(j+1, N, 1):
            if (arr[i][ny] == 'O'):
                break
            elif (arr[i][ny] == 'S'):
                return False
        # 하
        for ny in range(j-1, -1, -1):
            if (arr[i][ny] == 'O'):
                break
            elif (arr[i][ny] == 'S'):
                return False
        # 좌 
        for nx in range(i+1, N, 1):
            if (arr[nx][j] == 'O'):
                break
            elif (arr[nx][j] == 'S'):
                return False
        # 우
        for nx in range(i-1, -1, -1):
            if (arr[nx][j] == 'O'):
                break
            elif (arr[nx][j] == 'S'):
                return False
    return True

success = 'NO'
for ob in obstacle:
    for i, j in ob:
        arr[i][j] = 'O'
        
    flag = check(arr, teacher)
    if (flag == True):
        success = 'YES'
        break
    
    for i, j in ob:
        arr[i][j] = 'X'
print(success)
