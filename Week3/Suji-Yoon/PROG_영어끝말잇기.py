def solution(n, words):
    answer = []
    dict = {}
    fail = False
    cnt = 0
    last_word = ''
    for i in range(len(words)):
        if (i != 0 and last_word != words[i][0]):
            fail = True
            cnt = i
            break
        if (len(words[i]) == 0):
            fail = True
            cnt = i
            break
        if (words[i] in dict):
            fail = True
            cnt = i
            break
        dict[words[i]] = 1
        last_word = words[i][-1]

    if (fail):
        answer.append(cnt % n + 1)
        if (i == 0):
            answer.append(1)
        else:
            answer.append(cnt // n + 1)
    else:
        answer.extend([0,0])    
    
    return answer
