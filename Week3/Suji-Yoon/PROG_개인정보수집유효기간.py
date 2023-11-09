def solution(today, terms, privacies):
    answer = []
    term = {}
    today_y, today_m, today_d = map(int, today.split('.'))
    for i in range(len(terms)):
        tag, duration = terms[i].split()
        term[tag] = int(duration)
    
    for i in range(len(privacies)):
        date, tag = privacies[i].split()
        year, month, day = map(int, date.split('.'))
        
        expire_month = month + term[tag]
        year += (expire_month - 1) // 12
        month = 12 if expire_month % 12 == 0 else expire_month % 12
        
        if (year < today_y):
            answer.append(i+1)
        elif (year == today_y and month < today_m):
            answer.append(i+1)
        elif (year == today_y and month == today_m and day <= today_d):
            answer.append(i+1)
        
    return answer
