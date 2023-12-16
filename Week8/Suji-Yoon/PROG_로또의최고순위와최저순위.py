def solution(lottos, win_nums):
    prize = {6: 1, 5:2, 4:3, 3:4, 2:5, 1:6, 0:6}
    cnt = lottos.count(0)
    hit = 0
    
    for num in lottos:
        if (num in win_nums):
            hit += 1

    answer = [prize[cnt+hit], prize[hit]]
    return answer
