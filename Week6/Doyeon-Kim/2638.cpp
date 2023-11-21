#include <iostream>
#include <queue>

using namespace std;

int map[101][101];
int cnt=0;

bool checkRange(int n, int m, int x, int y) {
    return x>=0 && x<n && y>=0 && y<m;
}

queue<pair<int, int> > cheese;

void bfs(int n, int m) {
    int x,y,nx,ny;
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    bool visited[101][101]={false,};
    queue<pair<int, int> > air;

    air.push(make_pair(0,0));

    while(!air.empty()) {
        x=air.front().first;
        y=air.front().second;
        air.pop();

        for(int i=0; i<4; i++) {
            nx=x+dx[i];
            ny=y+dy[i];

            if(map[nx][ny]==2) {
                map[nx][ny]=0;
            }

            if(checkRange(n,m, nx, ny) && !visited[nx][ny]) {
                visited[nx][ny] = true;
                if(map[nx][ny]==0) {
                    air.push(make_pair(nx, ny));
                } else {
                    cheese.push(make_pair(nx, ny));
                }
            }
        }
    }

    while(!cheese.empty()) {
        x=cheese.front().first;
        y=cheese.front().second;
        cheese.pop();

        int tmp=0;

        for(int i=0; i<4; i++) {
            nx=x+dx[i];
            ny=y+dy[i];

            if(map[nx][ny]==0 && visited[nx][ny]){
                tmp++;
            }
        }

        if(tmp>=2) {
            map[x][y]=2;
            cnt++;
        }
    }

    return;
}

int main() {
    int n, m;
    int total=0;
    int time=0;

    cin >> n >> m;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> map[i][j];
            if(map[i][j]==1) {
                total++;
            }
        }
    }

    while(cnt<total) {
        bfs(n,m);
        time++;
    }

    cout << time;

    return 0;
}