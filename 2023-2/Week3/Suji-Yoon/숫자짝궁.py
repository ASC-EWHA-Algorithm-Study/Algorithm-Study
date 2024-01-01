def solution(X, Y):
    x = [0 for _ in range(10)]
    y = [0 for _ in range(10)]
    
    for i in range(len(X)):
        x[int(X[i])] += 1
    for i in range(len(Y)):
        y[int(Y[i])] += 1
    
    answer = ''
    for i in range(9, -1, -1):
        answer += min(x[i], y[i]) * str(i)

    
    if (len(answer) == 0):
        answer = '-1'
    # elif (int(answer) == 0): -> 시간초과
    #     answer = '0'
    elif (answer[0] == '0'):
        answer = '0'
    
    return answer
