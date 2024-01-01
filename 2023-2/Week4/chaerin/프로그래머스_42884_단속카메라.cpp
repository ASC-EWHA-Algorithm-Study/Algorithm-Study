#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


int solution(vector<vector<int>> routes) {
    int answer = 0;
    int n=routes.size();
    
    sort(routes.begin(),routes.end());

    // for(int i=0;i<n;i++){
    //     int camera=routes[i][1];
    //     for(int j=i+1;j<n;j++){
    //         if(routes[j][0]<=camera)i++;
    //         else break;
    //         if(routes[j][1]<=camera)camera=routes[j][1];
    //     }
    //     answer++;
    // }
    
    int camera=-30001;
    for(int i=0;i<n;i++){
        if(routes[i][0]>camera){
            answer++;
            camera=routes[i][1];
        }
         if(routes[i][1]<=camera){
            camera = routes[i][1];
        }
    }
    
    return answer;
}
