#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int map[500][500];
int route[500][500]={0};
int n;
int m;

typedef struct element {
    int height;
    int x;
    int y;
};

bool checkRange(int x, int y) {
    return x>=0 && x<n && y>=0 && y<m;
}

struct compare {
    bool operator()(const element& m1, const element& m2) {
        return m1.height < m2.height;
    }
};

int dfs() {
    int x,y,nx,ny;
    int dx[4]={1,0,0,-1};
    int dy[4]={0,1,-1,0};
    priority_queue<element, vector<element>, compare> pq;

    element e={map[0][0], 0, 0};
    pq.push(e);

    while(!pq.empty()) {
        x=pq.top().x;
        y=pq.top().y;
        pq.pop();

        for(int i=0; i<4; i++) {
            nx=x+dx[i];
            ny=y+dy[i];

            if(checkRange(nx,ny) && map[nx][ny]<map[x][y]) {
                //방문한 적 없으면
                if(route[nx][ny]==0) {
                    route[nx][ny]=route[x][y];
                    element ne={map[nx][ny], nx, ny};
                    pq.push(ne);
                } else {
                    route[nx][ny]+=route[x][y];
                }
            }
        }
    }

    return route[n-1][m-1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> map[i][j];
        }
    }

    route[0][0]=1;
    cout << dfs();

    return 0;
}

//BFS+우선순위 큐
//높이 높은 칸부터 탐색하게 해 가짓수 다 확인할 수 있도록