import sys 

N = int(sys.stdin.readline())
paper = []

for i in range(N) : 
    numbers = list(map(int, sys.stdin.readline().split(' ')))
    paper.append(numbers)

result = []

def solution(x,y,N) :
    color = paper[x][y]
    for i in range(x, x+N) : 
        for j in range(y, y+N) :
            if color != paper[i][j] :
                # return 문을 제거하면
                # 함수가 현재 정사각형 내에서 다른 색상을 찾은 후에도 
                # 계속 실행되어서 여전히 루프의 나머지 요소를 확인하고 
                # 네 개의 사분면 각각에 대해 재귀 호출을 수행한다.
                # 이로 인해 불필요한 재귀 호출이 발생할 수 있다.
                solution(x,y,N//2)
                solution(x,y+N//2, N//2) 
                solution(x+N//2, y, N//2)
                solution(x+N//2, y+N//2, N//2)
                return
    if color == 0 :
        result.append(0)
    else : 
        result.append(1)
        
solution(0,0,N)
print(result.count(0))
print(result.count(1))
