import sys 

def solution(words) : 
    # 3. 중복된 단어는 하나만 남기고 제거 
    word_list = set(words)
    word_list = list(word_list)
    
    # 1. 길이가 짧은 것부터
    # 2. 길이가 같으면 사전 순으로
    
    # 먼저 사전 순으로 정렬을 하고, 길이 순으로 정렬을 해야함
    # 반대로 하면 길이순으로 정렬이 된게 사전 순으로 정렬을 하면서 흐트러지고 만다 
    word_list.sort()
    word_list.sort(key = len)

    
    for word in word_list : 
        print(word)

if __name__ == "__main__" : 
    N = int(sys.stdin.readline())
    
    words = []
    
    for i in range(N) : 
        words.append(sys.stdin.readline().strip())
        
    solution(words)