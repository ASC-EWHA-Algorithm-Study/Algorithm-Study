def solution(numbers, hand):
    dx = [1, -1, 0, 0]
    dy = [0, 0, 1, -1]
    keypad = [(3,1),(0,0),(0,1),(0,2),(1,0),(1,1),(1,2),(2,0),(2,1),(2,2)]
    # 왼손, 오른손 위치
    left = (3,0)
    right = (3,2)
    answer = ''
    for num in numbers:
        if (num in [1, 4, 7]):
            answer += 'L'
            left = keypad[num]
        elif (num in [3, 6, 9]):
            answer += 'R'
            right = keypad[num]
        else: 
            left_dist = abs(left[0] - keypad[num][0]) + abs(left[1] - keypad[num][1])
            right_dist = abs(right[0] - keypad[num][0]) + abs(right[1] - keypad[num][1])
            if (left_dist > right_dist):
                answer += 'R'
                right = keypad[num]
            elif (left_dist < right_dist):
                answer += 'L'
                left = keypad[num]
            else:
                if (hand == 'left'): 
                    answer += 'L'
                    left = keypad[num]
                else: 
                    answer += 'R'
                    right = keypad[num]
    return answer
