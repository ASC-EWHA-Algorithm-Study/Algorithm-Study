def solution(new_id):
    # Step 1
    step1 = new_id.lower()
    # Step 2
    step2 = ''
    for i in step1:
        if (i == '-' or i == '_' or i == '.' or 97 <= ord(i) <= 122 or 48 <= ord(i) <= 57):
            step2 += i
    # Step 3
    step3 = ''
    cnt = 0
    for i in range(len(step2)):
        if (step2[i] == '.'):
            cnt += 1
        else:
            if (cnt > 0): 
                step3 += '.' + step2[i]
                cnt = 0
            else: 
                step3 += step2[i]
    # Step 4
    start = 0
    end = False
    for i in range(len(step3)):
        if (i == 0 and step3[i] == '.'):
            start = 1
        if (i == len(step3) - 1 and step3[i] == '.'):
            end = True
    if (end): step4 = step3[start:-1]
    else: step4 = step3[start::]
    # Step 5
    if (len(step4) == 0):
        step5 = step4 + 'a'
    else:
        step5 = step4
    # Step6
    if (len(step5) >= 16):
        step6 = step5[0:15]
        if (step6[-1] == '.'):
            step6 = step6[0:-1]
    else: step6 = step5
    # Step7
    if (len(step6) == 1):
        step7 = step6 + step6[-1] * 2
    elif (len(step6) == 2):
        step7 = step6 + step6[-1]
    else:
        step7 = step6
    return step7
