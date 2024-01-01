import sys

N = int(sys.stdin.readline())

time = []
for i in range(N) : 
    start, end = map(int, sys.stdin.readline().split(" "))
    time.append([start,end])
    
# 주어진 시작시간과 끝나는 시간들을 이용해서 가장 많은 회의의 수를 알기 위해서는 빨리 끝나는 회의 순서대로 정렬을 해야 한다. 
# 빨리 끝날수록 뒤에서 고려해볼 회의가 많기 때문이다. 
# 빨리 시작하는 순서대로 정렬을 우선 한다면, 오히려 늦게 끝날 수 있기 때문이다.
new_time = sorted(time, key = lambda x: (x[1],x[0]))

# 그리고 한가지 더 고려해야 하는 점이 있는데, 끝나는 시간이 같을 경우이다.
# 끝나는 시간이 같다면 빨리 시작하는 순서대로 정렬이 되어야 한다.
# 예를 들자면
# 2
# 2 2
# 1 2
# 의 경우 이 상태로 한다면 (2 2)가 되고 (1 2)는 (2 2)의 끝나는 시간보다 시작시간이 일찍이기 때문에 무시되어 1번의 회의가 진행된다고 나온다.
# 하지만 정렬을 통해 (1 2)가 먼저 선택되면 (2 2)도 선택이 가능해지기 때문에 가능한 회의는 2번으로 결정된다.

# 끝나는 시간
last = 0 

# 회의 개수
count = 0 

for i, j in time :
    if i >= last:
        count += 1
        last = j

print(count)
    