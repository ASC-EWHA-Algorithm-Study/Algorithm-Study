def solution(s):
    answer = len(s)
    for i in range(len(s)//2, 0, -1):
        now = ''
        j = 0
        while ((j + 2*i) <= len(s)):
            next = j + i
            cnt = 1
            while (s[j:j+i] == s[next:next+i]):
                cnt += 1
                next += i
            if (cnt != 1):
                now += str(cnt) + str(s[j:j+i])
            else:
                now += str(s[j:j+i])
            j = next
        now += str(s[j:])
        answer = min(answer, len(now))
    return answer
