import sys
    
N, M = map(int, sys.stdin.readline().split(" "))
logs = list(map(int, sys.stdin.readline().split(" ")))

def binary_search(arr, start, end) : 
    ans = 0
    while start <= end : 
        mid = (start + end) // 2
        total = 0 
        
        for x in arr : 
            if x > mid :
                total += x - mid 
            
        if total > M : 
            ans = mid 
            start = mid +1 
        elif total == M : 
            ans = mid 
            break
        else : 
            end = mid - 1
    return ans 

print(binary_search(logs, 0, max(logs))) 