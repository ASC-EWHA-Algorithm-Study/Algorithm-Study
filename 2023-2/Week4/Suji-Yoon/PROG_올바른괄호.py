def solution(s):
    answer = True
    st = []
    for i in s:
        if (i == '('):
            st.append(i)
        else:
            if (len(st) == 0):
                return False
            st.pop()
    if (len(st) == 0):
        return True
    return False
