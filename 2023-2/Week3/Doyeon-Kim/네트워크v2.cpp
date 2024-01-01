#include <string>
#include <vector>
#include <queue>

using namespace std;

bool visited[201]={false};

int dfs(int n, vector<vector<int>> computers) {
    visited[n]=true;

    for(int i=0; i<computers[n].size(); i++) {
        if(!visited[i] && computers[n][i]) {
            dfs(i, computers);
        }
    }

    return 0;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    for(int i=0; i<n; i++) {
        if(!visited[i]) {
            dfs(i, computers);
            answer++;
        }
    }

    return answer;
}

//재귀 함수 이용해 DFS 구현