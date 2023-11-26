#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

bool bfs(pair<int, int> home, pair<int, int> festival, vector<pair<int,int> > store, int beer) {
    queue<pair<int, int> > q;
    int x, y;
    store.push_back(festival);
    int n=store.size();
    vector<bool> visited(n, false);

    q.push(home);

    while(!q.empty()) {
        x=q.front().first;
        y=q.front().second;
        q.pop();

        if(x==festival.first && y==festival.second) {
            return true;
        }

        for(int i=0; i<n; i++) {
            if(!visited[i] && abs(x-store[i].first)+abs(y-store[i].second)<=1000) {
                visited[i]=true;
                q.push((make_pair(store[i].first, store[i].second)));
            }
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t, n, x, y;
    pair<int,int> home;
    pair<int,int> festival;

    cin >> t;

    while(t--) {
        vector<pair<int,int> > store;
        cin >> n;
        cin >> home.first >> home.second;
        for(int i=0; i<n; i++) {
            cin >> x >> y;
            store.push_back(make_pair(x,y));
        }
        sort(store.begin(), store.end());
        cin >> festival.first >> festival.second;

        if(bfs(home, festival, store, 20)) {
            cout << "happy" << "\n";
        } else {
            cout << "sad" << "\n";
        }
    }

    return 0;
}

//BFS
//편의점 방문 여부 저장