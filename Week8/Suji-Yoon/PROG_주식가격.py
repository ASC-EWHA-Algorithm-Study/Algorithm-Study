def solution(prices):
    answer = [i for i in range(len(prices)-1, -1, -1)]
    st = [(0, prices[0])]
    for i in range(1, len(prices)):
        # print(st)
        while (len(st) > 0 and st[-1][1] > prices[i]):
            idx, price = st.pop()
            # print(idx, price, i)
            answer[idx] = i - idx
        st.append((i, prices[i]))
        # print(answer)
            
    return answer
