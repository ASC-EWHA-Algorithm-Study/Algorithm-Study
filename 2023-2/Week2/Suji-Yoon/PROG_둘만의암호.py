def changeAlphabet(s, arr, idx):
    index = 0
    cur = ord(s) - ord('a')

    while index < idx:
        print('index: ', index, ' cur: ', cur)
        cur = (cur + 1) % 26
        if (arr[cur] == True):
            index += 1

    return chr(cur + ord('a'))
            

def solution(s, skip, index):
    arr = [True] * 26
    for i in skip:
        arr[ord(i) - ord('a')] = False

    answer = ''
    for i in s:
        answer += changeAlphabet(i, arr, index)

    return answer
