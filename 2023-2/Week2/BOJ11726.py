import sys

def solution(N) : 
    dp = [0] * 1001
    
    dp[1] = 1
    dp[2] = 2
    
    for i in range(3,N+1) :
        dp[i] = dp[i-1] + dp[i-2]
        
    # dp[3] = 3 (2+1)
    # dp[4] = 4(2*2) + 2(2*1) -1  = 5
    # dp[5] = dp[4] + dp[3] = 8
    # dp[6] = dp[5] +dp[4] = 13
    # dp[7] = 13 + 8 = 21
    
    return dp[N] % 10007
    

if __name__ == "__main__" : 
    N = int(sys.stdin.readline())
    
    print(solution(N))