#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int map[101][101];

bool isValid(int next_x, int next_y, int n) {
    return next_x>=0 && next_x<n && next_y>=0 && next_y<n;
}

int bfs(int n) {
    int result=0;
    bool visited[101][101]={false};

    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};

    queue<pair<int, int> > q;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            //방문 안 하고 안 잠긴 애
            if(!visited[i][j] && map[i][j]>0) {
                q.push(make_pair(i, j));
                visited[i][j]= true;

                while(!q.empty()) {
                    pair<int, int> p = q.front();
                    q.pop();

                    for(int k=0; k<4; k++) {
                        int next_x=p.first+dx[k];
                        int next_y=p.second+dy[k];

                        if(isValid(next_x, next_y, n) && map[next_x][next_y]>0 && !visited[next_x][next_y]) {
                            q.push(make_pair(next_x, next_y));
                            visited[next_x][next_y]= true;
                        }
                    }
                }
                result++;
            }
        }
    }

    return result;
}

void rain(int n) {
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(map[i][j]>0) {
                map[i][j]--;
            }
        }
    }
}

int main() {
    int n;
    int max_height=0;
    int result=0;
    cin >> n;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> map[i][j];
            if(map[i][j]>max_height) {
                max_height=map[i][j];
            }
        }
    }

    //높이
    for(int i=0; i<max_height; i++) {
        result=max(result, bfs(n));
        rain(n);
    }

    cout << result;

    return 0;
}

//완전 기본 BFS!