import sys 

N = int(sys.stdin.readline())

graph = []
result = []

for i in range(N) : 
    numbers = list(map(int, sys.stdin.readline().split(" ")))
    graph.append(numbers)

def solution(x,y,N) : 
    number = graph[y][x] 
    for i in range(y, y+N) :
        for j in range(x, x+N) : 
            if number != graph[i][j] : 
                solution(x,y,N//3)
                solution(x+N//3,y,N//3)
                solution(x+(2*N//3),y,N//3)
                solution(x,y+N//3,N//3)
                solution(x,y+(2*N//3),N//3)
                solution(x+N//3,y+N//3,N//3)
                solution(x+N//3,y+(2*N//3),N//3)
                solution(x+(2*N//3),y+N//3,N//3)
                solution(x+(2*N//3),y+(2*N//3),N//3)
                return
    result.append(number)

solution(0,0,N)
print(result.count(-1))
print(result.count(0))
print(result.count(1))