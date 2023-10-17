def solution(coins, K) : 
    answer = 0
    change = K
    
    coins.sort(reverse=True)
    
    for coin in coins : 
        if change // coin > 0  : 
            answer += change // coin
            change -= coin * (change//coin)
        
        if change == 0 : 
            break 
    
    return answer

if __name__ == "__main__" : 
    N, K = map(int, input().split(" "))
    
    coins = []
    for i in range(N) : 
        coins.append(int(input()))
        
    print(solution(coins, K))