import sys
input = sys.stdin.readline

N, C = map(int, input().split())
x = []
for _ in range(N):
    x.append(int(input()))

# 가장 인접한 두 공유기 사이의 거리 -> 탐색 값
x.sort()
start = 0
end = x[-1] - x[0]
answer = end

while (start <= end):
    mid = (start + end) // 2
    before = x[0]
    cnt = 1
    for i in range(1, N):
        if (x[i] - before >= mid):
            cnt += 1
            before = x[i]
        else:
            continue
    if (cnt >= C):
        answer = mid
        start = mid + 1
    else:
        end = mid - 1
        
print(answer)
