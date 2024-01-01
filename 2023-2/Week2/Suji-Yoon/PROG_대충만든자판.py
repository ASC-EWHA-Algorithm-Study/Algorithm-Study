def solution(keymap, targets):
    alphabet = [101] * 26
    for key in keymap:
        for i in range(len(key)):
            k = key[i]
            alphabet[ord(k) - ord('A')] = min(alphabet[ord(k) - ord('A')], i+1)

    answer = []
    for target in targets:
        cnt = 0
        flag = False
        for i in target:
            if (alphabet[ord(i) - ord('A')] > 100):
                flag = True
                break
            else:
                cnt += alphabet[ord(i) - ord('A')]
        if (flag):
            answer.append(-1)
        else:
            answer.append(cnt)
    return answer
