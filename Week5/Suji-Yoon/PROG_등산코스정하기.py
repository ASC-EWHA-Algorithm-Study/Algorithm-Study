import heapq
INF = 10 ** 9

def solution(n, paths, gates, summits):
    arr = [[] for _ in range(n+1)]
    summits = set(summits)

    for i, j, w in paths:
        arr[i].append((j,w))
        arr[j].append((i,w))

    intensity = [INF] * (n+1)
    q = []
    
    for gate in gates:
        intensity[gate] = 0
        heapq.heappush(q, (0, gate))

    while q:
        cost, now = heapq.heappop(q)
        if (now in summits):
            continue
        if (intensity[now] < cost):
            continue
        for next_node, next_weight in arr[now]:
            next_cost = max(next_weight, cost)
            if (intensity[next_node] > next_cost):
                intensity[next_node] = next_cost
                heapq.heappush(q, (next_cost, next_node))
    
    answer = [INF, INF]
    for s in summits:
        if (answer[1] > intensity[s]):
            answer = [s, intensity[s]]
        elif (answer[1] == intensity[s] and answer[0] > s):
            answer = [s, intensity[s]]
    
    return answer
