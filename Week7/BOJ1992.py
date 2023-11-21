import sys 
from collections import deque

N = int(sys.stdin.readline())
graph = []
result = ""

for i in range(N) : 
    numbers = [int(char) for char in sys.stdin.readline().strip()]
    graph.append(numbers)
    
def solution(x,y,N) : 
    global result
    number = graph[y][x]
    for i in range(y, y+N) :
        for j in range(x, x+N) : 
            if number != graph[i][j] : 
                result += "("
                solution(x, y, N//2)
                solution(x + N//2, y, N//2)
                solution(x, y+N//2, N//2)
                solution(x + N//2, y + N//2, N//2)
                result += ")"
                return 
    result += str(number)

solution(0,0,N)

print(result)
