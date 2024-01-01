#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
int n, arr[1000][1000], dp[1000][1000];   
int max1;
cin>>n;
  
for (int i = 0;i < n;i++) {
	for (int j = 0;j < i + 1;j++) {
    cin>>arr[i][j];	 
	}
}

dp[0][0] = arr[0][0];   

for (int i = 1;i < n;i++) {
	for (int j = 0;j < i + 1;j++) {
		dp[i][j]=max(dp[i-1][j],dp[i-1][j-1])+arr[i][j];
	}
}

max1 = dp[n-1][0];

for (int i = 0;i < n;i++) {
	if (dp[n-1][i] >= max1)               
		max1 = dp[n-1][i];
}
cout<<max1;
}
