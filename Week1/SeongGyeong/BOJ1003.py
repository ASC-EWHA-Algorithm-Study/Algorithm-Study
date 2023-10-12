# 시간초과
"""
def fibonacci(n,cnt) : 
    if n == 0 : 
        cnt[0] += 1
        return 0
    elif n ==1 : 
        cnt[1] += 1
        return 1
    else : 
        return fibonacci(n-1,cnt) + fibonacci(n-2,cnt)

def solution(numbers) :
    for number in numbers : 
        cnt = [0,0]
        fibonacci(number,cnt)
        print(cnt[0], cnt[1])
"""

# 10^8이 1초인데, 시간 제한이 0.25초이고 입력은 40개 
# 재귀로 구현한 피보나치를 쓰면 2^40이기 때문에 10^8도 넘어간다 
# 반복문을 통한 dp로 구현해야겠다는 생각을 여기서 할 수 있음

""" 
0 - 1 0 
1 - 0 1
2 - 1 1
3 - 1 2
4 - 2 3
5 - 3 5 
6 - 5 8 
7 - 8 13 

-> 규칙 cnt_zero == 직전 N의 cnt_one / cnt_zero = 직전 N의 cnt_zero + cnt_one
"""

def solution(numbers) : 
    cnt_zero = [1] 
    cnt_one = [0] 
    for number in numbers : 
        for i in range(1, number+1) : 
            cnt_zero.append(cnt_one[-1])
            cnt_one.append(cnt_one[-1] + cnt_zero[-2])
        print(cnt_zero[number], cnt_one[number])
        

if __name__ == "__main__" : 
    T = int(input())
    
    numbers = []
    for i in range(T) : 
        numbers.append(int(input()))

    solution(numbers)