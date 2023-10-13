# 시간 제한이 타이트 -> 반복문은 사용할 수 없음 

# X가 3으로 나누어 떨어지면, 3으로 나눈다.
# X가 2로 나누어 떨어지면, 2로 나눈다.
# 1을 뺀다.

# 위와 같은 연산 세 개를 적절히 사용해서 1을 만들려고 한다.

import math 

def solution(N) : 
    # 인덱스 n에 대하여, n을 1로 만드는 최소 연산의 횟수이다.
    dp = [0] * (N+1)
    
    # dp[1]은 이미 1이니까 0이라서 시작점이 2
    for i in range(2, N+1) : 
        # 2,3으로 나눠 떨어지지 않는 경우에는 1을 빼야하기 때문에 일단 횟수 + 1을 해준다. 
        # bottom-up이라서 1을 뺀다 => 1을 더한다로 생각해보면 되고, 1을 더하기만 했으니까 하나 작은 수의 횟수에 1을 더하면 됨
        dp[i] = dp[i-1] + 1 
        
        if i % 2 == 0 : 
            dp[i] = min(dp[i], dp[i/2] + 1)
        if i % 3 == 0 : 
            dp[i] = min(dp[i], dp[i/3] + 1)
            
        # ex ) 6 => 6/2 == 3 / 3/3 == 1
    
    print(dp[N])
    
    
    # temp = N // 3 if N % 3 == 0 else N - 3* (N//3)
    # answer += math.floor(math.log(N,3))
    
    # temp = temp // 2 if temp % 2 == 0 or temp < 2 else temp - 2* (N//2)
    # if temp != 0 : 
    #     answer += math.floor(math.log(temp,2)) 
    
    # if temp == 1 : 
    #     return answer + 1
    # else : 
    #     answer += temp 
    #     return answer 
    
if __name__ == "__main__" : 
    N = int(input())
    print(solution(N))
    
    
    