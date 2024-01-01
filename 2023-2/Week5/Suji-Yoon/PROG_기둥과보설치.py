def check_valid(x, y, a, arr, n, remove=False):
    if (remove and arr[a][x][y] != 1): return True
    if (x >= 0 and x <= n and y >= 0 and y <= n):
        # 기둥
        if (a == 0):
            if (y == 0 or arr[0][x][y-1] == 1 or (x < n and arr[1][x][y] == 1) or (x > 0 and arr[1][x-1][y] == 1)):
                return True
        # 보
        else:
            if ((y > 0 and arr[0][x][y-1] == 1) or (y > 0 and x < n and arr[0][x+1][y-1] == 1) or (x > 0 and arr[1][x-1][y] == 1 and x < n and arr[1][x+1][y] == 1)):
                return True
    return False
        
def solution(n, build_frame):
    answer = []
    arr = [[[0] * (n+1) for _ in range(n+1)] for _ in range(2)] # 기둥 & 보
    
    for x, y, a, b in build_frame:
        if (b == 1): # 설치
            if (check_valid(x, y, a, arr, n)):
                arr[a][x][y] = 1
                answer.append([x, y, a])
        else: # 삭제
            arr[a][x][y] = 0
            # (x,y) 기둥 삭제하는 경우
            if (a == 0):
                # (x, y+1) 기둥, (x, y+1) 보, (x-1, y+1) 보
                if ((y == n-1 or check_valid(x, y+1, 0, arr, n, True)) and (x == n or check_valid(x, y+1, 1, arr, n, True)) and (x == 0 or check_valid(x-1, y+1, 1, arr, n, True))):
                    answer.remove([x, y, a])
                else:
                    arr[a][x][y] = 1
            
            # (x,y) 보 삭제하는 경우
            else:
            # (x,y) 기둥, (x+1, y) 기둥, (x-1, y) 보, (x+1, y) 보
                if ((y == n or check_valid(x, y, 0, arr, n, True)) and (y == n or check_valid(x+1, y, 0, arr, n, True)) and (x == 0 or check_valid(x-1, y, 1, arr, n, True)) and (x == n-1 or check_valid(x+1, y, 1, arr, n, True))):
                    answer.remove([x, y, a])
                else:
                    arr[a][x][y] = 1
                
    
    answer.sort(key = lambda x : (x[0], x[1], x[2]))
    return answer
        
