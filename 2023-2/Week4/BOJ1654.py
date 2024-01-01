import sys 

K, N = map (int, sys.stdin.readline().split(" "))
lan_cables = []
for i in range(K) : 
    lan_cables.append(int(sys.stdin.readline()))
    
def binary_search(arr, start, end) :
    ans = 0 
    while start <= end : 
        mid = (start + end) // 2 
        total = 0 
        
        for x in arr : 
            if x >= mid : 
                total += x // mid 
            
        if total < N : 
            end = mid - 1 
        else : 
            ans = mid 
            start = mid + 1
    return ans

# 조건이 자연수인데 start를 0으로 해서 틀렸음!
print(binary_search(lan_cables, 1, max(lan_cables)))