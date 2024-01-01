#include <vector>
#include <queue>
#include <iostream>

using namespace std;
int visited[100][100]={0,};
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int maxM=0, maxN=0;
vector<vector<int>> pictureG;


int dfs(int m,int n){
    int answer=1;
    int color=pictureG[m][n];
    queue <pair<int,int>> q;
    q.push(make_pair(m,n));
    visited[m][n]=1;
    while(!q.empty()){
        
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(0 > nx || nx >= maxM || 0 > ny || ny >= maxN) continue;
            if (pictureG[nx][ny] == color && visited[nx][ny] == 0) {
                visited[nx][ny]=1;
                q.push(make_pair(nx,ny));
                answer++;
            }
        }
    }
    return answer;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    // visited[100][100]={0,};
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            visited[i][j] = 0;
        }
    }
    maxM=m; maxN=n;

    pictureG=picture;
    // cout<<pictureG[4][3];
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(visited[i][j]==0&&picture[i][j]!=0){
                int nan=dfs(i,j);
                if(nan>max_size_of_one_area)max_size_of_one_area=nan;
                number_of_area++;
            }
        }
    }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}
