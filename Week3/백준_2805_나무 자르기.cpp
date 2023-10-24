#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int N,K;
    queue <int> q;
    queue <int> ans;
    cin>>N>>K;
    for(int i=0;i<N;i++){
        q.push(i+1);
    }
    while(!q.empty()){
        for(int i=0;i<K-1;i++){
            int temp=q.front();
            q.pop();
            q.push(temp);
        }
        ans.push(q.front());
        q.pop();
    }
    cout<<'<';
    for(int i=0;i<N-1;i++) {
        cout<<ans.front()<<", ";
        ans.pop();
    }
    cout<<ans.front()<<'>';
    return 0;
}
