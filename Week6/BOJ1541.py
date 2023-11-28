import sys 


# 결국 '-'를 기준으로 해서 괄호를 치면 된다.
# '-'를 기준으로 괄호를 쳐주면 되기 때문에 
# input을 받을 때 '-'를 기준으로 split 한다
exp = sys.stdin.readline().split("-")

num = []
start = 0 

for i in exp : 
    sum = 0 
    # +로 묶인 애들은 다 더해주기 위해 +로 split한다
    tmp = i.split("+")
    for j in tmp : 
        sum += int(j)
    num.append(sum)
    
# 시작하는 수에서 나머지를 다 빼줘야하니까 
ans = num[0]

for i in range(1, len(num)) :
    ans -= num[i]
    
print(ans)