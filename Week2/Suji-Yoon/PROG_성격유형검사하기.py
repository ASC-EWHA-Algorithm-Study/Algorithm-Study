def solution(survey, choices):
    type = {'R': 0, 'T': 0, 'C': 0, 'F': 0, 'J': 0, 'M': 0, 'A': 0, 'N': 0}
    answer = ''
    for i in range(len(choices)):
        if (choices[i] < 4):
            print(survey[i][0])
            type[survey[i][0]] += abs(choices[i] - 4)
        else:
            print(survey[i][1])
            type[survey[i][1]] += abs(choices[i] - 4)
    
    if (type['R'] >= type['T']):
        answer += 'R'
    else:
        answer += 'T'
    if (type['C'] >= type['F']):
        answer += 'C'
    else:
        answer += 'F'
    if (type['J'] >= type['M']):
        answer += 'J'
    else:
        answer += 'M'
    if (type['A'] >= type['N']):
        answer += 'A'
    else:
        answer += 'N'
    return answer
