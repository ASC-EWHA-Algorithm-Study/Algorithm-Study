#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = 0;
    int v=attacks.size();
    int time=attacks[v-1][0];
    int max=health;
    int cnt=0;
    int plus=bandage[1];
    int j=0;
    for(int i=0;i<=time;i++){
        cout<<health<<" ";
        if(health<0)break;
        if(i==attacks[j][0]){
            cout<<"으악 ";
            cnt=0;
            health-=attacks[j][1];
            j++;
        }else{
            cnt++;
            health+=plus;
            if(cnt==bandage[0]){ health+=bandage[2];  cnt=0;}
            if(health>max) health=max;
        }
    }
    answer=health;
    if(answer<=0)answer=-1;
    return answer;
}
