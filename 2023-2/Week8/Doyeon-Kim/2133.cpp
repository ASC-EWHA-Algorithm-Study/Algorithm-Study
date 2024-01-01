#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    if(n%2==1) {
        cout << 0;
        return 0;
    }

    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    dp[2] = 3;

    for(int i=4; i<=n; i+=2) {
        dp[i]=dp[i-2]*3;
        for(int j=0; j<=i-4; j+=2) {
            dp[i]+=dp[j]*2;
        }
    }

    cout << dp[n];

    return 0;
}

//DP