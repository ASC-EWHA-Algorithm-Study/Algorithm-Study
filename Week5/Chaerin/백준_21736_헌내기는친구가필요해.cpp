#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
int n,m;
int startRow, startCol;
char campus[601][601];
int visited[601][601];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};


int bfs(){
    int ans=0;
    queue <pair<int,int>> q;
    q.push(make_pair(startRow,startCol));
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){ // 상하좌우
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0 > nx || nx >= n || 0 > ny || ny >= m) continue;
            if(campus[nx][ny] == 'X' || visited[nx][ny]) continue;
            if(campus[nx][ny] == 'P') ans++;
            visited[nx][ny] = 1;
            q.push(make_pair(nx,ny));
        }
    }
    return ans;
}

int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> campus[i][j];
            if(campus[i][j] == 'I') startRow = i, startCol = j;
        }
    }
    int ans=bfs();
    if( ans >0 ) cout<< ans;
    else cout <<"TT";
    return 0;
}
