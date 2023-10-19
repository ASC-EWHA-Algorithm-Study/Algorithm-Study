#include <string>
#include <vector>
#include <iostream> 
#include <algorithm>
#include <queue>

using namespace std;



int solution(int n, vector<vector<int>> edge) {

    
    
    int s=edge.size();
    vector<vector<int>> graph(n+1);
    for(int i=0;i<s;i++){
        int from=edge[i][0];
        int to=edge[i][1];
        
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    
    vector<int> dist(n+1, -1);
    
    queue<int> q; 
    q.push(1); 
    dist[1]=0; 
    while(!q.empty()){
        int current = q.front(); 
        q.pop(); 
        int d = dist[current]; 
        for(int i=0; i<graph[current].size(); i++){
            int next = graph[current][i]; 
            if(dist[next]!=-1)continue; 
            dist[next] = d+1;      
            q.push(next); 
        }
    }
    
    sort(dist.begin(),dist.end(), greater<>());
    int answer = 1;
    for(int i=1;i<n;i++){
        if(dist[i]<dist[0])break;
        else answer++;
    }
    
    
    
    

    
    
    return answer;
}

