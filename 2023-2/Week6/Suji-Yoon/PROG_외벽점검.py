import itertools

def solution(n, weak, dist):
    # 완전탐색: 모든 시작 위치 x 가능한 친구 순열 조합
    answer = len(dist) + 1
    len_weak = len(weak)
    for i in range(len_weak):
        weak.append(n + weak[i])
    # 가능한 모든 친구 순열 조합
    friends = itertools.permutations(dist)
    

    for friend in list(friends):
        for start in range(len_weak):
            cnt = 0 # 친구 index
            check = 0 # 점검 완료한 갯수
            next_position = weak[start] + friend[cnt] # 검사할 수 있는 지점
            for i in range(start, start + len_weak):
                if (weak[i] <= next_position):
                    check += 1
                    if (check == len_weak):
                        break
                else:
                    cnt += 1
                    if (cnt >= len(dist)):
                        break
                    next_position = weak[i] + friend[cnt]

            answer = min(answer, cnt+1)
    if (answer == len(dist) + 1): answer = -1
    return answer
