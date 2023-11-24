#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define INF 987654321

int main() {
    int n, m, s, d, w;
    cin >> n >> m;
    vector<vector<int> > city(n+1, vector<int>(n+1, INF));

    for(int i=0; i<m; i++) {
        cin >> s >> d >> w;
        city[s][d]=min(city[s][d],w);
    }

    for(int k=1; k<=n; k++) {
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                city[i][j]=min(city[i][j], city[i][k]+city[k][j]);
            }
        }
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            if(city[i][j]==INF || i==j) {
                cout << 0 << " ";
            } else {
                cout << city[i][j] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}