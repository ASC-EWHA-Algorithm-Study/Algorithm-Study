#include<vector>
#include<queue>

using namespace std;

bool checkRange(int x, int y, int n, int m) {
    return x>=0 && x<n && y>=0 && y<m;
}

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    queue<pair<int, int>> q;
    int n = maps.size();
    int m = maps[0].size();
    bool visited[101][101]={false};

    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,1,-1};

    int x,y,next_x,next_y;

    q.push(make_pair(0,0));
    maps[0][0]=1;
    while(!q.empty()) {
        x=q.front().first;
        y=q.front().second;
        q.pop();

        for(int i=0; i<4; i++) {
            next_x=x+dx[i];
            next_y=y+dy[i];

            //범위 안이고 벽 아니고 방문 안 했을 때
            if(checkRange(next_x, next_y, n, m) && !visited[next_x][next_y] && maps[next_x][next_y]!=0) {
                maps[next_x][next_y]=maps[x][y]+1;
                q.push(make_pair(next_x, next_y));
                visited[next_x][next_y]=true;
            }
        }
    }

    if(maps[n-1][m-1]==1) {
        answer=-1;
    } else {
        answer=maps[n-1][m-1];
    }

    return answer;
}

//최단거리 BFS