import sys
import itertools
input = sys.stdin.readline
INF = 10 ** 9

N, M = map(int, input().split())
arr = []
chicken = []
house = []
for i in range(N):
    arr.append(list(map(int, input().split())))
    for j in range(N):
        if (arr[i][j] == 2):
            chicken.append((i,j))
        elif (arr[i][j] == 1):
            house.append((i,j))
    
# 완전 탐색
answer = INF
combination = list(itertools.combinations(chicken, M))
for comb in combination:
    dist = 0
    for i, j in house:
        min_dist = INF
        for x, y in comb:
            min_dist = min(min_dist, abs(i-x) + abs(j-y))
        dist += min_dist
    answer = min(answer, dist)
print(answer)
    
