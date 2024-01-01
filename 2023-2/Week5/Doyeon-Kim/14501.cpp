#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, end, cost;
    cin >> n;

    vector<int> v(n+1,0);

    for(int i=1; i<=n; i++) {
        cin >> end >> cost;

        //날짜 범위 넘으면 패스
        if((i+end-1)>n) {
            continue;
        }

        //값 갱신
        if(v[i+end-1]<v[i-1]+cost) {
            for(int j=i+end-1; j<=n; j++) {
                v[j]=max(v[j],v[i-1]+cost);
            }
        }
    }

    cout << v[n];

    return 0;
}

//실버3 DP