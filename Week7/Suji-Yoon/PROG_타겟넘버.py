def dfs(numbers, target, cnt, value):
    # print('dfs >> ', cnt, value)
    global answer
    if (cnt == len(numbers)):
        if value == target:
            answer += 1
        return
    dfs(numbers, target, cnt+1, value+numbers[cnt])
    dfs(numbers, target, cnt+1, value-numbers[cnt])

def solution(numbers, target):
    # + - 2가지 경우만 존재
    global answer
    answer = 0
    dfs(numbers, target, 0, 0)
    return answer
