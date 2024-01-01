import sys
input = sys.stdin.readline
INF = 10 ** 10

n = int(input())
m = int(input())
arr = [[INF] * (n+1) for _ in range(n+1)]
for _ in range(m):
    a, b, c = map(int, input().split())
    # 시작 도시와 도착 도시를 연결하는 노선은 하나가 아닐 수 있다.
    arr[a][b] = min(arr[a][b], c)

for i in range(n+1):
    arr[i][i] = 0
    
for k in range(1, n+1):
    for i in range(1, n+1):
        for j in range(1, n+1):
            arr[i][j] = min(arr[i][j], arr[i][k]+arr[k][j])

for i in range(1, n+1):
    for j in range(1, n+1):
        if (arr[i][j] == INF):
            print(0, end = ' ')
        else:
            print(arr[i][j], end = ' ')
    print()
