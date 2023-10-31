import sys
input = sys.stdin.readline

N = int(input())
arr = []
for _ in range(N):
    arr.append(list(map(int, input().split())))
    
dp = [[0] * N for _ in range(N)]
dp[0][0] = arr[0][0]
for i in range(1, N):
    for j in range(len(arr[i])):
        if (j == 0):
            dp[i][j] = arr[i][j] + dp[i-1][j]
        elif (j == i):
            dp[i][j] = arr[i][j] + dp[i-1][j-1]
        else:
            dp[i][j] = arr[i][j] + max(dp[i-1][j], dp[i-1][j-1])

print(max(dp[N-1]))
