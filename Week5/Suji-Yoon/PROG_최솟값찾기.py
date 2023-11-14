def solution(A,B):
    answer = 0
    A.sort()
    B.sort()
    n = len(A)
    nn = len(A)
    cnt = 0
    i = 0
    while (cnt < nn):
        
        if (A[i] * B[n - i - 1] < A[n - i - 1] * B[i]):
            answer += A[i]*B[n-i-1]
            del A[i]
            del B[n-i-1]
        else:
            answer += A[n-i-1]*B[i]
            del A[n-i-1]
            del B[i]
        cnt += 1
        n -= 1


    return answer
