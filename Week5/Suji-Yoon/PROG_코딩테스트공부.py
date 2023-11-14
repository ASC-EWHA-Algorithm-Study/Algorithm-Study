INF = 10**6

def solution(alp, cop, problems):
    max_algo = 0
    max_code = 0
    for i in range(len(problems)):
        max_algo = max(max_algo, problems[i][0])
        max_code = max(max_code, problems[i][1])
        
    # 런타임 에러
    max_algo = max(max_algo, alp)
    max_code = max(max_code, cop)
    
    dp = [[INF] * (max_code + 1) for _ in range(max_algo + 1)]
    dp[alp][cop] = 0
    
    for i in range(alp, max_algo + 1):
        for j in range(cop, max_code + 1):
            # 공부하는 경우
            if (i+1 <= max_algo):
                dp[i+1][j] = min(dp[i+1][j], dp[i][j]+1)
            if (j+1 <= max_code):
                dp[i][j+1] = min(dp[i][j+1], dp[i][j]+1)
            # 문제 푸는 경우
            for k in range(len(problems)):
                alp_req, cop_req, alp_rwd, cop_rwd, cost = problems[k]
                if (i >= alp_req and j >= cop_req):
                    next_alp, next_cop = min(max_algo, i + alp_rwd), min(max_code, j + cop_rwd)
                    dp[next_alp][next_cop] = min(dp[next_alp][next_cop], dp[i][j] + cost)

    return dp[max_algo][max_code]
