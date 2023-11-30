#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
#include <set>
using namespace std;

vector<vector<int>> group_land;  // Updated to use vector

int N, M;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

int bfs(int n, int m, vector<vector<int>>& land, int num) {
    int oil = 0;
    queue<pair<int, int>> q;
    group_land[n][m] = num;
    q.push(make_pair(n, m));
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        oil++;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < N && ny >= 0 && ny < M && land[nx][ny] == 1 && group_land[nx][ny] == 0) {
                q.push(make_pair(nx, ny));
                group_land[nx][ny] = num;
            }
        }
    }
    return oil;
}

int solution(vector<vector<int>> land) {
    int answer = 0;
    M = land[0].size();
    N = land.size();
    group_land.assign(N, vector<int>(M, 0));  // Initialize group_land with zeros

    vector<int> oiloil(1, 0);
    int k = 0;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (land[j][i] == 1 && group_land[j][i] == 0) {
                k++;
                int oil = bfs(j, i, land, k);
                oiloil.push_back(oil);
            }
        }
    }

    set<int> s;
    for (int i = 0; i < M; i++) {
        int temp = 0;
        for (int j = 0; j < N; j++) {
            if (group_land[j][i] != 0) s.insert(group_land[j][i]);
        }
        for (auto it : s) {
            temp += oiloil[it];
            cout << it;
        }
        if (answer < temp) answer = temp;
        s.clear();
    }

    return answer;
}
