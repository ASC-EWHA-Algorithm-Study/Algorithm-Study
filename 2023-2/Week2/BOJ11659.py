import sys
input = sys.stdin.readline

N, M = map(int, input().split())
arr = list(map(int, input().split()))
pre_sum = [0]

temp = 0
for i in arr:
    temp += i
    pre_sum.append(temp)
    
for _ in range(M):
    a, b = map(int, input().split())
    print(pre_sum[b] - pre_sum[a-1])