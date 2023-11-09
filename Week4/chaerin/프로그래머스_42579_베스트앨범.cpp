#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;


bool comp(pair<int,int> a, pair<int,int> b) {
    if(a.second == b.second) return a.first<b.first;
    return a.second > b.second;
}

struct str{
    int play;
    vector <pair<int,int>> song;
};

map<string,str> genre;

static bool cmp(pair<string, str>& a, pair<string, str>& b){
	return a.second.play > b.second.play;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    for(int i=0;i<genres.size();i++){
        genre[genres[i]].play+=plays[i];
        
        genre[genres[i]].song.push_back(make_pair(i,plays[i]));
    }

    vector<pair<string,  str>> v(genre.begin(), genre.end());

    sort(v.begin(), v.end(), cmp);

    
    for(int i=0;i<v.size();i++){
        sort(v[i].second.song.begin(),v[i].second.song.end(),comp);
        
        answer.push_back(v[i].second.song[0].first);
        if(v[i].second.song.size()>1)answer.push_back(v[i].second.song[1].first);
    }
    
    
    
    return answer;
}
