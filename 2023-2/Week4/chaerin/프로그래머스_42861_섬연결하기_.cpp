#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;
int island[100][100]={0,};


bool connected(int n){
    bool visited[100]={0,};
    queue <int> q;
    q.push(0);
    visited[0]=true;
    while(!q.empty()){
        int now=q.front();
        q.pop();
        for(int i=0;i<n;i++){
            if(island[now][i]==1&&visited[i]==false){q.push(i); visited[i]=true;}
        }
    }
    for(int i=0;i<n;i++){
        if(visited[i]==false) return false;
    }
    return true;
}

bool cmp(vector<int> cost1, vector<int> cost2){
    return cost1[2]<cost2[2];
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    sort(costs.begin(),costs.end(),cmp);
    int i=0;
    int j=0;
    int bri=costs.size();
    while(connected(n)==false){
        int i1=costs[i][0];
        int i2=costs[i][1];
        int cost=costs[i][2];
        island[i1][i2]=1;
        island[i2][i1]=1;
        answer+=cost;
        i++;
    }
    
    return answer;
}
