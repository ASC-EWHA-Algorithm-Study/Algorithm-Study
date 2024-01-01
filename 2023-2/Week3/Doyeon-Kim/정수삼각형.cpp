#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int height = triangle.size();

    /*탑다운
    for(int i=1; i<height; i++) {
         for(int j=0; j<triangle[i].size(); j++) {
             if(j==0) {
                 triangle[i][j]+=triangle[i-1][j];
             } else if(j==triangle[i].size()-1) {
                 triangle[i][j]+=triangle[i-1][j-1];
             } else {
                 triangle[i][j]+=max(triangle[i-1][j-1], triangle[i-1][j]);
             }
         }
     }

     for(int i=0; i<triangle[height-1].size(); i++) {
         answer=max(answer, triangle[height-1][i]);
     } */

    //바텀업
    for(int i=height-2; i>=0; i--) {
        for(int j=triangle[i].size()-1; j>=0; j--) {
            triangle[i][j]+=max(triangle[i+1][j], triangle[i+1][j+1]);
        }
    }

    answer = triangle[0][0];

    return answer;
}

//DP 탑다운보다 바텀업이 더 간결하고 빠름