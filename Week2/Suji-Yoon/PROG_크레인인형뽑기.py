def solution(board, moves):
    result = [0] # 뽑은 인형
    answer = 0
    for i in moves:
        for j in range(len(board)):
            if (board[j][i-1] != 0):
                if (result[-1] == board[j][i-1]):
                    answer += 2
                    result.pop()
                else:
                    result.append(board[j][i-1])
                board[j][i-1] = 0
                break
                
    return answer
