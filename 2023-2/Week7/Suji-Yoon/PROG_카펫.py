def solution(brown, yellow):
    for i in range(1, yellow//2+2):
        if (yellow % i != 0):
            continue
        j = yellow // i
        if ((i + j)*2 + 4 == brown):
            return [j+2, i+2]
