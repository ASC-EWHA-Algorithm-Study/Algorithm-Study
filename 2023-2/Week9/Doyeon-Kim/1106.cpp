#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 987654321

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int c, n;
    int add=0;
    int result=MAX;
    cin >> c >> n;

    vector<vector<int> > v(n,vector<int>(2,0));

    for(int i=0; i<n; i++) {
        cin >> v[i][0] >> v[i][1];
        add = max(v[i][1], add);
    }

    vector<int> cost(c+add+1, MAX);

    cost[0]=0;
    for(int i=1; i<cost.size(); i++) {
        for(int j=0; j<n; j++) {
            if(v[j][1]<=i) {
                cost[i]=min(cost[i], cost[i-v[j][1]]+v[j][0]);
            }
        }
        if(i>=c) {
            result=min(result, cost[i]);
        }
    }

    cout << result;

    return 0;
}

//DP
//비용 배열 int 최댓값으로 초기화