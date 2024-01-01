#include <iostream>
#include <vector>
#include <algorithm>
#include<utility>

using namespace std;
vector<pair<int,int>> ladder;
vector<pair<int,int>> snake;
int N,M;

int play(int now, int target){
    if(now==target)return 0;
    for(int i=0;i<N;i++){
        if(now<=ladder[i].first&&ladder[i].second<=target){
            return play(now,ladder[i].first)+play(ladder[i].second,target);
        }
    }
    int answer=0;
    
    int arr[M];
    for(int i=0;i<M;i++){
        arr[i]=snake[i].first;
    }
    
    while(now<target){
        if(target-now>6){
            for(int i=6;i>0;i--){
                int move=now-i;
                bool exists = std::find(arr, arr + M, move) != arr + M;
                if(!exists) {
                    answer++;
                    now=move;
                    break;
                }
            }
        }
    }
    return answer;
}

bool cmp_lad(pair<int,int> a, pair<int,int> b){
    return (a.second-a.first)>(b.second-b.first);
}
bool cmp_snk(pair<int,int> a, pair<int,int> b){
    return (a.first)>(b.first);
}

int main()
{
    
    cin>>N>>M;

    for(int i=0;i<N;i++){
        int x,y;
        cin>>x>>y;
        ladder.push_back(make_pair(x, y));
    }
    sort(ladder.begin(),ladder.end(),cmp_lad);
    for(int i=0;i<M;i++){
        int u,v;
        cin>>u>>v;
        snake.push_back(make_pair(u, v));
    }
    sort(snake.begin(),snake.end(),cmp_snk);
        
    int answer=play(0,100);
    cout<<answer;
    
    return 0;
}
