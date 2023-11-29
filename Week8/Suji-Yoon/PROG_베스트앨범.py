def solution(genres, plays):
    answer = []
    song = {}
    genre = {}
    l = len(genres)
    for i in range(l):
        if (song.get(genres[i])):
            genre[genres[i]] += plays[i]
            song[genres[i]].append((i, plays[i]))
        else:
            genre[genres[i]] = plays[i]
            song[genres[i]] = [(i, plays[i])]

    genre = list(genre.items())
    genre.sort(key = lambda x : x[1], reverse=True)
    for g in genre:
        cnt = 0
        for i in sorted(song[g[0]], key = lambda x: x[1], reverse=True):
            if (cnt >= 2): break
            answer.append(i[0])
            cnt += 1
    
    return answer
