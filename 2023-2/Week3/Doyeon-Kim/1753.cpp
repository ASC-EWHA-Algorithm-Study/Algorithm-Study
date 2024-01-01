#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 600000000

vector<int> dijkstra(int k, int v, vector<vector<pair<int, int> > > graph) {
    vector<int> dist(v+1, INF);
    priority_queue<pair<int, int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
    dist[k]=0;

    pq.push(make_pair(0,k));
    while(!pq.empty()) {
        int weight=pq.top().first;
        int node=pq.top().second;
        pq.pop();

        if(dist[node]<weight) {
            continue;
        } else {
            for(int i=0; i<graph[node].size(); i++) {
                int next_node=graph[node][i].first;
                int next_weight=dist[node]+graph[node][i].second;

                if(dist[next_node]>next_weight) {
                    dist[next_node]=next_weight;
                    pq.push(make_pair(next_weight, next_node));
                }
            }
        }

    }

    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int v,e,k,a,b,w;
    cin >> v >> e >> k;

    vector<vector<pair<int, int> > >graph(v+1, vector<pair<int, int> >());

    for(int i=0; i<e; i++) {
        cin >> a >> b >> w;
        graph[a].push_back(make_pair(b,w));
    }

    vector<int> dist = dijkstra(k, v, graph);

    for(int i=1; i<dist.size(); i++) {
        if(dist[i]==INF) {
            cout << "INF" << endl;
        } else {
            cout << dist[i] << endl;
        }
    }

    return 0;
}

//다익스트라 구현