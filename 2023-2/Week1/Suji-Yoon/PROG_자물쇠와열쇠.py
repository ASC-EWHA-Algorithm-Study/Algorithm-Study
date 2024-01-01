import numpy as np

def rotation_clock(key):
    result = [[] for _ in range(len(key))]
    for i in range(len(key)-1, -1, -1):
        for j in range(len(key)):
            result[j].append(key[i][j])
    return result

def match_key(key, lock, lock_expand, x, y):
    visit = [[False] * (len(lock)) for _ in range(len(lock))]
    for i in range(len(key)):
        for j in range(len(key)):
            if (lock_expand[x+i][y+j] == -1): continue
            if (lock_expand[x+i][y+j] == key[i][j]):
                return False
            else:
                visit[x+i-len(key)+1][y+j-len(key)+1] = True
    for i in range(len(lock)):
        for j in range(len(lock)):
            if (visit[i][j] == False and lock[i][j] == 0):
                return False
    return True                

def solution(key, lock):
    key_one = rotation_clock(key)
    key_two = rotation_clock(key_one)
    key_three = rotation_clock(key_two)
    
    lock_expand = np.pad(np.array(lock), pad_width=len(key)-1, mode='constant', constant_values=-1)
    for i in range(len(lock_expand) - len(key)+1):
        for j in range(len(lock_expand) - len(key)+1):
            a = match_key(key, lock, lock_expand, i, j)
            b = match_key(key_one, lock, lock_expand, i, j)
            c = match_key(key_two, lock, lock_expand, i, j)
            d = match_key(key_three, lock, lock_expand, i, j)
            if (a == True or b == True or c == True or d == True):
                return True
    return False
