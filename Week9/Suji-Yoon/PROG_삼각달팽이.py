def solution(n):
    answer = []
    arr = [[0] * n for _ in range(n)]
    num = 1
    total = n*(n+1) / 2
    x, y = (0, 0)
  
    for i in range(n-1, -1, -3):
        for _ in range(i):
            arr[x][y] = num
            x += 1
            num += 1
            if (num > total): break
        for _ in range(i):
            arr[x][y] = num
            y += 1
            num += 1
            if (num > total): break
        for _ in range(i-1):
            arr[x][y] = num
            x -= 1
            y -= 1
            num += 1
            if (num > total): break
        arr[x][y] = num
        num += 1
        x += 1
      
    for i in range(n):
        for j in range(n):
            if (arr[i][j] != 0):
                answer.append(arr[i][j])
    return answer
