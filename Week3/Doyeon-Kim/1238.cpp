#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define INF 1000000

vector<int> dijkstra(int n, int x, vector<vector<pair<int, int> > > graph) {
    vector<int> dist(n+1, INF);
    priority_queue<pair<int, int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
    int weight, node, next_weight, next_node;

    dist[x]=0;

    pq.push(make_pair(0,x));
    while(!pq.empty()) {
        weight=pq.top().first;
        node=pq.top().second;
        pq.pop();

        if(dist[node]<weight) {
            continue;
        }

        for(int i=0; i<graph[node].size(); i++) {
            next_weight=graph[node][i].second;
            next_node=graph[node][i].first;

            if((dist[node]+next_weight)<dist[next_node]) {
                dist[next_node]=dist[node]+next_weight;
                pq.push(make_pair(next_weight, next_node));
            }
        }
    }

    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, x;
    int a, b, w;
    int go, back;
    int max=0;
    cin >> n >> m >> x;

    vector<vector<pair<int, int> > >back_graph(n+1, vector<pair<int, int> >());
    vector<vector<pair<int, int> > >go_graph(n+1, vector<pair<int, int> >());
    vector<int> go_dist;
    vector<int> back_dist;

    for(int i=0; i<m; i++) {
        cin >> a >> b >> w;
        back_graph[a].push_back(make_pair(b, w));
        go_graph[b].push_back(make_pair(a, w));
    }

    go_dist = dijkstra(n, x, back_graph);
    back_dist = dijkstra(n, x, go_graph);

    for(int i=1; i<go_dist.size(); i++) {
        go = go_dist[i];
        back = back_dist[i];
        if(go!=INF && back!=INF && (go+back)>max) {
            max = go+back;
        }
    }

    cout << max;

    return 0;
}