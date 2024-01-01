import sys 

def dfs(x, y) : 
    # dfs의 방문처리 시점은 실제로 그 지점을 방문한 직후에 처리
    
    """
    dfs는 범위내에있고 방문한적이 없다면 갈수있을때까지 파고든다. 
    즉, 방문가능지역 검사에서 만난 순서와 실제 탐색지역의 순서는 별개이다. 

    그런데 만약 방문가능지역을 검사하는 과정에서(보통 for문을 통해 사방탐색) 방문처리를 미리 하면 어떻게 될까?
    방문처리를 미리 한다고 해서 방문하지 않는곳이 생기지는 않는다.

    그러나 스택을 이용하여 dfs를 구현할때 visit처리를 미리 해준다면 방문순서를 좌표상에 표시해야할때 
    문제가 생긴다. 
    실제 방문순서와 방문가능지역 탐색순서가 다르기 때문이다.
    """
    visited[y][x] = True
    global count 
    count += 1
    
    for i in range(4) : 
        nx, ny = x + dx[i] , y + dy[i]
        if 0<=nx<len(graph) and 0<=ny<len(graph) and visited[ny][nx] == False and graph[ny][nx] == 1:
            # visited[ny][nx] = True 
            # 이렇게 하면 첫 좌표가 방문 처리가 되지 않아서 두 번 방문하게 됨 
            # 그래서 답이 1씩 크게 나옴
            """ 반례
            5
            10101
            01010
            10101
            01010
            10101
            """
            dfs(nx,ny)
        


N = int(sys.stdin.readline())
graph = []
ans = []
count = 0

for i in range(N) : 
    numbers = [int(char) for char in sys.stdin.readline().strip()]
    graph.append(numbers)

dx = [-1, 1, 0, 0]
dy = [0, 0 , -1, 1]

visited = [[False for i in range(25)] for j in range(25)]

for i in range(len(graph)) : 
    for j in range(len(graph)) : 
        # if graph[i][j] == 1 and visited[i][j] == False:
        #  x + dx[i] , y + dy[i] 이 부분 때문에 둘이 반대로 적어줘야 x+dx[i]가 됨
        if graph[j][i] == 1 and visited[j][i] == False:
            dfs(i, j)
            ans.append(count)
            count = 0 
    
ans.sort()

print(len(ans))
for i in ans : 
    print(i)

    
    
