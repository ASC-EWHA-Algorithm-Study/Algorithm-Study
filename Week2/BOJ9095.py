import sys 

# 인덱스 에러 어디서?

def solution(number) : 
    dp = [0] * (12)
    
    dp[1] = 1
    dp[2] = 2
    
    for i in range(3, number +1) : 
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3] 
        if (dp[i-1] == 0) : 
            dp[i] += 1
        if (dp[i-2] == 0) : 
            dp[i] += 1
        if (dp[i-3] == 0) : 
            dp[i] += 1
    
    return dp[number]
    

if __name__ == "__main__" : 
    N = int(sys.stdin.readline())
    
    numbers = []
    for _ in range(N) : 
        num = int(sys.stdin.readline())
        numbers.append(num)
    
    for number in numbers : 
        print(solution(number))