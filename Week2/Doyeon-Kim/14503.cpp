#include <iostream>
#include <queue>

using namespace std;

int map[51][51];

//x y 범위 다름!!!!!
bool checkRange(int x, int y, int n, int m) {
    return x>=0 && x<n && y>=0 && y<m;
}

int bfs(int n, int m, int r, int c, int d) {
    int result=0;
    queue<pair<int, int> > q;
    pair<int, int> p;
    int x, y, next_x, next_y, next_d;

    //북 동 남 서
    int dx[4]={-1,0,1,0};
    int dy[4]={0,1,0,-1};

    q.push(make_pair(r,c));

    while(!q.empty()) {
        p = q.front();
        x=p.first;
        y=p.second;
        q.pop();

        if(map[x][y]==0) {
            map[x][y]=2;
            result++;
        }

        bool check=false;

        for(int i=0; i<4; i++) {
            next_d=(d+3-i)%4;
            next_x=x+dx[next_d];
            next_y=y+dy[next_d];

            if(checkRange(next_x, next_y, n, m) && !map[next_x][next_y]) {
                q.push(make_pair(next_x, next_y));
                check=true;
                d=next_d;
                break;
            }
        }

        //청소되지 않은 빈칸 없으면
        if(!check) {
            next_x=x-dx[d];
            next_y=y-dy[d];

            //후진할 수 있으면
            if(checkRange(next_x, next_y, n, m) && map[next_x][next_y]!=1) {
                q.push(make_pair(next_x, next_y));
            } else if(map[next_x][next_y]==1) {
                return result;
            }
        }
    }

    return result;
}

int main() {
    int n, m;
    int r, c, d;

    cin >> n >> m;
    cin >> r >> c >> d;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> map[i][j];
        }
    }

    cout << bfs(n, m, r, c, d);

    return 0;
}