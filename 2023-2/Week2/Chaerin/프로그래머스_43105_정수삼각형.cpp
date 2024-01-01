#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int n=triangle.size();
    vector<vector<int>> tri_max(n, vector<int>(n));

    
    cout<<n;
    tri_max[0][0]=triangle[0][0];
    for(int i=1;i<n;i++){
        tri_max[i][0]=tri_max[i-1][0]+triangle[i][0];
        for(int j=1;j<i;j++){
            tri_max[i][j]=max(tri_max[i-1][j],tri_max[i-1][j-1])+triangle[i][j];
        }
        tri_max[i][i]=tri_max[i-1][i-1]+triangle[i][i];
     }
    
    for(int i=0;i<n;i++){
        if(answer<tri_max[n-1][i])answer=tri_max[n-1][i];
    }
    
    return answer;
}
