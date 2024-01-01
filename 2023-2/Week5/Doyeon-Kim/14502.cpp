#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int map[9][9];

bool checkRange(int nx, int ny, int n, int m) {
    return nx>=0 && nx<n && ny>=0 && ny<m;
}

int bfs(vector<pair<int, int> > wall, queue<pair<int, int> > q, int n, int m) {
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,1,-1};
    int x, y, nx, ny;
    int count=0;
    int visited[9][9]={ false };

    //벽 세우고
    for(int i=0; i<wall.size(); i++) {
        map[wall[i].first][wall[i].second]=1;
    }
    //바이러스 전파
    while(!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            nx=x+dx[i];
            ny=y+dy[i];
            if(checkRange(nx, ny, n, m) && !visited[nx][ny] && map[nx][ny]==0) {
                visited[nx][ny]=true;
                q.push(make_pair(nx,ny));
            }
        }
    }
    //남은 지역 카운트
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(!visited[i][j] && map[i][j]==0) {
                count++;
            }
        }
    }
    //벽 철거
    for(int i=0; i<wall.size(); i++) {
        map[wall[i].first][wall[i].second]=0;
    }

    return count;
}

int main() {
    int n, m, tmp;
    int safe=0;
    queue<pair<int, int> > q;
    vector<pair<int, int> > v;
    vector<pair<int, int> > wall;

    cin >> n >> m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> map[i][j];
            if(map[i][j]==2) {
                q.push(make_pair(i,j));
            }
            if(map[i][j]==0) {
                v.push_back(make_pair(i, j));
            }
        }
    }

    for(int i=0; i<v.size()-2; i++) {
        for(int j=i+1; j<v.size()-1; j++) {
            for(int k=j+1; k<v.size(); k++) {
                wall.push_back(v[i]);
                wall.push_back(v[j]);
                wall.push_back(v[k]);

                tmp = bfs(wall, q, n, m);
                safe = max(tmp, safe);
                wall.clear();
            }
        }
    }

    cout << safe << endl;

    return 0;
}