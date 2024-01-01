# 인자인 N이 음수로 내려갔을 때에 대한 처리가 안되고 있는 것 같음 - 재귀식으로 푸는 것을 버리자. 
# def dp(N,stairs,stairSum) : 
#     if N <= 2 :  
#         return sum(stairs)
#     else : 
#         stairSum[N] = max(dp(N-2,stairs,stairSum) + stairs[N], dp(N-3,stairs,stairSum)+stairs[N-1]+stairs[N])

def solution(N, stairs): 
    stairSum = [0] * (N+1)
    
    stairSum[1] = stairs[1]
    stairSum[2] = stairs[1] + stairs[2]
        
    for i in range(3, N+1) : 
        stairSum[i] = max(stairSum[i-2] + stairs[i], stairSum[i-3] + stairs[i-1] + stairs[i])
            
    return stairSum[N]
        

if __name__ == "__main__" : 
     N = int(input())
     
     stairs = [0]
     for i in range(N) : 
         stairs.append(int(input()))
    
     print(solution(N,stairs))
         

# f(n) = max(f(n-2) + stairs(n), f(n-3)+stairs(n-1)+stairs(n))

# 6 

# 4           3

# 2   1      1 0




