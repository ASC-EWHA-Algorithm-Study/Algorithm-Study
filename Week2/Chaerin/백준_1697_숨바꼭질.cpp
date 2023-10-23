#include <iostream>
#include <queue>

using namespace std;

bool visited[100010];

int main()
{
    int N,K;
    cin>>N>>K;

    
    queue<pair<int, int>> q;
    
    pair<int, int> first=make_pair(N,0);
    q.push(first);
    int answer;
    while(!q.empty()){
        pair<int, int> n=q.front();
        q.pop();
        if(n.first==K){
            answer=n.second;
            break;
        }
        if(n.first+1<=K&&visited[n.first+1]==false){
            visited[n.first+1]=true;
            q.push(make_pair(n.first+1,n.second+1));
        }
        if(n.first-1>=0&&visited[n.first-1]==false){
            visited[n.first-1]=true;
            q.push(make_pair(n.first-1,n.second+1));
        }
        if(n.first*2<=K+1&&visited[n.first*2]==false){
            visited[n.first*2]=true;
            q.push(make_pair(n.first*2,n.second+1));
        }
    }
    cout<<answer;

    return 0;
}
