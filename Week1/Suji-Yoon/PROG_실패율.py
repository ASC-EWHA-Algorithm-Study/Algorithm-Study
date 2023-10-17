def solution(N, stages):
    fail_rate = [0] * (N+1)
    stages.append(0)
    stages.sort(reverse=True)
    stage = N
    idx = 0
    fail = 0
    while (stage > 0 and idx < len(stages)):
        if (stages[idx] > stage):
            idx += 1
        elif (stages[idx] == stage):
            fail += 1
            idx += 1
        else:
            if (idx != 0):
                fail_rate[stage] = fail / idx
            stage -= 1
            fail = 0
    answer = sorted(range(1, N+1), key = lambda x : fail_rate[x], reverse=True)
    return answer
