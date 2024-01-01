import sys
input = sys.stdin.readline

N = int(input())
arr = list(map(int, input().split()))

dp = [(0, 0)] * N

for i in range(N):
    max_dp = 0
    cnt_dp = 0
    idx_dp = -1
    cnt = 0
    for j in range(i):
        if (arr[j] > arr[i]): 
            if (max_dp < dp[j][0]):
                max_dp = dp[j][0]
                cnt_dp = dp[j][1]
                idx_dp = j
        else:
            cnt += 1
    dp[i] = (max_dp + 1, cnt_dp + i - idx_dp - 1)
print(max(dp)[1] + N - dp.index(max(dp)) - 1)
