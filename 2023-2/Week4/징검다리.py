def solution(distance, rocks, n):
    answer = 0
    left, right = 0, distance
    rocks.sort()

    while left <= right:
        mid = (left+right)//2
        current, cnt = 0,0

        for rock in rocks:
            diff = rock - current
            if diff < mid:
                cnt += 1
            else:
                current=rock

        if cnt > n:
            right = mid-1
        else:
            left = mid+1
            answer = mid

    return answer