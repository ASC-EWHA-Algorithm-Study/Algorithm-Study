
#include <iostream>
#include <algorithm>

using namespace std;

int dp[1000][3];

int main()
{
    int n,a,b,c;
    cin>>n;
    cin>>dp[0][0]>>dp[0][1]>>dp[0][2];
    
    for(int i=1;i<n;i++){
        cin>>a>>b>>c;
        dp[i][0]=min(dp[i-1][1],dp[i-1][2])+a;
        dp[i][1]=min(dp[i-1][0],dp[i-1][2])+b;
        dp[i][2]=min(dp[i-1][1],dp[i-1][0])+c;
    }
    cout<<min(dp[n-1][0],min(dp[n-1][1],dp[n-1][2]));

    return 0;
}
