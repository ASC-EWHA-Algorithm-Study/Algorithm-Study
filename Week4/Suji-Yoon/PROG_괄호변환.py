def turn(p):
    ans = ''
    for i in p:
        if (i == '('):
            ans += ')'
        else:
            ans += '('
    if (len(ans) == 0):
        return ''
    else:
        return ans[1:-1]

def check_correct(p):
    st = []
    for i in p:
        if (i == '('):
            st.append(i)
        else:
            if (len(st) != 0):
                st.pop()
            else:
                return False
    if (len(st) != 0):
        return False
    return True

def divide(p):
    if (len(p) == 0):
        return ''
    left = 0
    right = 0
    u = ''
    v = ''
    for i in range(len(p)):
        if p[i] == '(':
            left += 1
        else:
            right += 1
        if (left == right):
            u = p[:i + 1]
            v = p[i + 1:]
            break
    if (check_correct(u)):
        u += divide(v)
        return u
    else:
        ans = '(' + divide(v) + ')'
        ans += turn(u)
        return ans
    
    
def solution(p):
    if (check_correct(p)):
        return p
    
    answer = divide(p)
    return answer
