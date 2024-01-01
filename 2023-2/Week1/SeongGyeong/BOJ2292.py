""" 내가 푼 풀이 
def solution(N) : 
    answer = 0
    plus = 0
    
    if N == 1: 
        return 1
    else : 
      num = ( N - 2 ) // 6 
      while True : 
          if(answer + plus <= num) : 
              answer += plus
              plus += 1
          else : 
              plus -= 1
              break
          
    return plus + 2

"""

def solution(N) : 
    num = 1
    cnt = 1
    while N > num : 
        num += 6 * cnt
        cnt += 1
    return cnt

    
if __name__ == "__main__" : 
    N = int(input())
    
    print(solution(N))
    
