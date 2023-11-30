def solution(clothes):
    closet = {}
    for name, category in clothes:
        if (category in closet):
            closet[category] += 1
        else:
            closet[category] = 1
    
    answer = 1
    for key in closet:
        answer *= closet[key] + 1
    return answer - 1
    
    # for i in range(2, len(closet)+1):
    #     combs = itertools.combinations(closet.keys(), i)
    #     for comb in combs:
    #         cnt = 1
    #         for key in comb:
    #             cnt *= closet[key]
    #         answer += cnt
    return answer
