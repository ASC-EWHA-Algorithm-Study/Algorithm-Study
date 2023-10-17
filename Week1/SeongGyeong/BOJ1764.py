# 그냥 list를 쓰면 시간초과 
"""
def solution(not_seen, not_heard) : 
    for name in not_heard : 
        if name in not_seen : 
            not_heard_not_seen.append(name)
            
    not_heard_not_seen.sort()
    print(len(not_heard_not_seen))
    for name in not_heard_not_seen : 
        print(name)

if __name__ == "__main__" : 
    N,M = map(int, input().split(" "))
    
    not_heard = []
    not_seen = []
    not_heard_not_seen = []
    
    for i in range(N): 
        not_heard.append(input())
    
    for i in range(M) : 
        not_seen.append(input())
        
    solution(not_seen, not_heard)
"""

import sys

def solution(not_seen, not_heard) : 
    not_heard_not_seen = []
    for name in not_heard : 
        if name in not_seen : 
            not_heard_not_seen.append(name)

    not_heard_not_seen.sort()
    print(len(not_heard_not_seen))
    for name in not_heard_not_seen : 
        print(name)

if __name__ == "__main__" : 
    # readline으로 받으면 input보다 훨씬 빠름
    N,M = map(int, sys.stdin.readline().split(" "))
    
    # set은 시간복잡도 O(1) - 해시테이블 사용하기 떄문에 인덱스 일일이 확인할 필요 X
    not_heard = set()
    not_seen = set()
    
    for i in range(N): 
        not_heard.add(sys.stdin.readline().strip())
    
    for i in range(M) : 
        not_seen.add(sys.stdin.readline().strip())
        
    solution(not_seen, not_heard)