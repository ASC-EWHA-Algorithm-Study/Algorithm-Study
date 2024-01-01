import sys

# 가장 득표수가 많은 사람을 계속 확인해서 매수해서 
# 다솜이의 득표수를 올리는 걸 반복하다가 
# 제일 득표수가 많은 사람이 다솜이보다 득표수가 낮아지는 순간 
# 매수를 멈추면 된다

N = int(sys.stdin.readline())
dasom_votes = int(sys.stdin.readline())
votes = []
for i in range(N-1) : 
    votes.append(int(sys.stdin.readline()))
votes.sort(reverse=True)

cnt = 0 

if N == 1: 
    print(0)
else : 
    while votes[0] >= dasom_votes : 
        dasom_votes += 1
        votes[0]-=1
        cnt +=1  
        votes.sort(reverse=True)  
    print(cnt)

    
    
