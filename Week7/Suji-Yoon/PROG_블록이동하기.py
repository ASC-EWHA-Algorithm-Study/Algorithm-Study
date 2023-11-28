from collections import deque

def get_next_pos(board, pos, N):
    next_pos = []
    pos = list(pos)
    x1, y1, x2, y2 = pos[0][0], pos[0][1], pos[1][0], pos[1][1]
    
    dx = [0, 0, 1, -1]
    dy = [1, -1, 0, 0]
    # 상하좌우
    for i in range(4):
        nx1, ny1 = x1 + dx[i], y1 + dy[i]
        nx2, ny2 = x2 + dx[i], y2 + dy[i]
        if (nx1 >= 0 and nx1 < N and ny1 >= 0 and ny1 < N and nx2 >=0 and nx2 < N and ny2 >=0 and ny2<N):
            if (board[nx1][ny1] == 0 and board[nx2][ny2] == 0):
                next_pos.append({(nx1, ny1), (nx2, ny2)})
    # 회전
    if (x1 == x2): # 가로
        for i in [1, -1]:
            if (x1+i >= 0 and x1 + i < N and x2+i >= 0 and x2+i < N and board[x1+i][y1] == 0 and board[x2+i][y2] == 0):
                next_pos.append({(x1, y1), (x1+i, y1)})
                next_pos.append({(x2, y2), (x2+i, y2)})
    else:
        for i in [1, -1]:
            if (y1+i >= 0 and y1+i < N and y2+i >= 0 and y2+i < N and board[x1][y1+i] == 0 and board[x2][y2+i] == 0):
                next_pos.append({(x1, y1), (x1, y1+i)})
                next_pos.append({(x2, y2), (x2, y2+i)})
    return next_pos

def solution(board):
    N = len(board)
    visit = []
    q = deque()
    
    pos = {(0,0), (0,1)}
    q.append((pos, 0))
    visit.append(pos)
    
    while q:
        pos, cost = q.popleft()
        if (N-1, N-1) in pos:
            return cost
        for next_pos in get_next_pos(board, pos, N):
            if next_pos not in visit:
                q.append((next_pos, cost+1))
                visit.append(next_pos)
    
    return 0
