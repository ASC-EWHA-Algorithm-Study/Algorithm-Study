def solution(wallpaper):
    lux = len(wallpaper)
    luy = len(wallpaper[0])
    rdx = -1
    rdy = -1
    # (가장 작은 x, y) -> 가장 큰 (x, y)
    for i in range(len(wallpaper)):
        for j in range(len(wallpaper[i])):
            if (wallpaper[i][j] == '#'):
                lux = min(lux, i)
                luy = min(luy, j)
                rdx = max(rdx, i+1)
                rdy = max(rdy, j+1)
    answer = [lux, luy, rdx, rdy]
    return answer
