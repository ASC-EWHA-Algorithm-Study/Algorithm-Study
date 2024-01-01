import sys
input = sys.stdin.readline

N = int(input())
arr = []
for _ in range(N):
    T, P = map(int, input().split())
    arr.append((T, P))

dp = [0]*(N+1)
for i in range(N):
    if (i + arr[i][0] < N+1):
        dp[i + arr[i][0]] = max(dp[i + arr[i][0]], max(dp[:i+1]) + arr[i][1])
    
print(max(dp))
    
