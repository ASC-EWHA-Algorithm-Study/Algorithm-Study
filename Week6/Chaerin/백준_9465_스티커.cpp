
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int testcase,n;
    int sticker[2][100000];
    cin>>testcase;
    for(int i=0;i<testcase;i++){
        int dp[2][100000]={0,};
        cin>>n;
        for(int j=0;j<n;j++){
            cin>>sticker[0][j];
        }
        for(int j=0;j<n;j++){
            cin>>sticker[1][j];
        }
        dp[0][0]=sticker[0][0];
        dp[0][1]=sticker[0][1]+sticker[1][0];
        dp[1][0]=sticker[1][0];
        dp[1][1]=sticker[1][1]+sticker[0][0];
        for(int j=2;j<n;j++){
            dp[0][j]=max(dp[1][j-1],dp[1][j-2])+sticker[0][j];
            dp[1][j]=max(dp[0][j-1],dp[0][j-2])+sticker[1][j];
        }
        cout<<max(dp[0][n-1],dp[1][n-1])<<"\n";
    }

    return 0;
}
