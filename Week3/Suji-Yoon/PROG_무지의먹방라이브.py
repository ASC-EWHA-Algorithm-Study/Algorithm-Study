def solution(food_times, k):
    sorted_arr = sorted(list(enumerate(food_times)), key = lambda x : x[1])
    cnt_food = len(sorted_arr)
    time = 0
    for i in range(len(sorted_arr)):
        idx, t = sorted_arr[i]
        if (cnt_food == 0):
            break
        # 이미 다 먹은 음식인 경우
        if (t <= time):
            cnt_food -= 1
            if (cnt_food == 0):
                break
            continue
        # 현재 남아 있는 음식 양 * 현재 가장 작은 시간 -> 한 바퀴를 돌고도 시간이 남는 경우
        if (k > (t - time) * cnt_food):
            k -= (t - time) * cnt_food
            time = t
            cnt_food -= 1
        # 한 바퀴를 돌지 못하는 경우 -> 현재 남아있는 음식에서 인덱스 계산
        else:
            if (k == (t-time) * cnt_food): 
                time = t
            index = k % cnt_food

            while (sorted_arr[i][1] <= time):
                i += 1
                cnt_food -= 1
                if (cnt_food == 0):
                    return -1
            index_sorted = sorted(sorted_arr[i:])
            return index_sorted[index][0] + 1
    return -1
  
