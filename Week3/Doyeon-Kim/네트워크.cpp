#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    queue<int> q;
    bool visited[201]={false};
    int x;

    for(int i=0; i<n; i++) {
        if(!visited[i]) {
            q.push(i);
            visited[i]=true;

            while(!q.empty()) {
                x=q.front();
                q.pop();

                for(int k=0; k<n; k++) {
                    if(!visited[k] && computers[x][k]) {
                        visited[x]=true;
                        q.push(k);
                    }
                }
            }
            answer++;
        }
    }

    return answer;
}

//BFS 좌표 아니고 컴퓨터 번호만 이용하는 거니까 이차원 배열 대신 일차원 배열로!!