import sys 

def solution(number) : 
    dp = [0] * 101
    dp[1], dp[2], dp[3], dp[4], dp[5] , dp[6], dp[7], dp[8], dp[9], dp[10] =  1, 1, 1, 2, 2, 3, 4, 5, 7, 9
    
    for i in range(11, number + 1) : 
        dp[i] = dp[i-1] + dp[i-5]
    
    return dp[number]    
    

if __name__ == "__main__" : 
    N = int(sys.stdin.readline())
    
    numbers = []
    for _ in range(N) : 
        numbers.append(int(sys.stdin.readline()))
        
    for number in numbers : 
        print(solution(number))
        
"""
dp[1] = 1 
dp[2] = 1
dp[3] = 1
dp[4] = 2
dp[5] = 2
dp[6] = 3 = dp[5] + dp[]
dp[7] = 4 = dp[6] + dp[2]
dp[8] = dp[7] + dp[3] = 5
dp[9] = 7 = dp[8] + dp[4]
dp[10] = dp[9] + dp[5] = 9 
dp[11] = dp[10] + dp[6]
dp[12] = dp[11] + dp[7]


"""