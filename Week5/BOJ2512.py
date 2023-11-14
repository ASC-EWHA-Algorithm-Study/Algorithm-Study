import sys 

N = int(sys.stdin.readline())
budget = list(map(int, sys.stdin.readline().split(" ")))
M = int(sys.stdin.readline())

def binary_search(budget, start, end) :
    ans = 0 
    while start <= end : 
        mid = (start + end) // 2
        total = 0 
        
        for x in budget : 
            if(x - mid >= 0): 
                total += mid 
            else : 
                total += x
        
        if total > M : 
            end = mid -1 
        else :
            ans = mid
            start = mid + 1
    return ans

print(binary_search(budget, 0, max(budget)))
            
    