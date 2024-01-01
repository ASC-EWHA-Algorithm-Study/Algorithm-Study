import sys
input = sys.stdin.readline
INF = 10**9

N = int(input())
num = list(map(int, input().split()))
operation = list(map(int, input().split()))

min_ans = INF
max_ans = -INF

def dfs(plus, minus, mul, div, cnt, tmp):
    global min_ans
    global max_ans
    
    if (cnt == N-1):
        min_ans = min(min_ans, tmp)
        max_ans = max(max_ans, tmp)
        return
    
    if (plus > 0):
        dfs(plus-1, minus, mul, div, cnt+1, tmp + num[cnt+1])
    if (minus > 0):
        dfs(plus, minus-1, mul, div, cnt+1, tmp - num[cnt+1])
    if (mul > 0):
        dfs(plus, minus, mul-1, div, cnt+1, tmp * num[cnt+1])
    if (div > 0):
        if (tmp > 0):
            dfs(plus, minus, mul, div-1, cnt+1, tmp // num[cnt+1])
        else:
            dfs(plus, minus, mul, div-1, cnt+1, abs(tmp) // num[cnt+1] * -1)



dfs(operation[0], operation[1], operation[2], operation[3], 0, num[0])
print(max_ans)
print(min_ans)
            
