#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <functional>

using namespace std;


vector<int> solution(vector<string> operations) {
    vector<int> answer;
    
    priority_queue<int, vector<int>, greater<int> > pq;
    
    for(int i=0;i<operations.size();i++){
        if(operations[i][0]=='I'){
            int num=stoi(operations[i].substr(2));
            cout<<num<<'\n';
            pq.push(num);
        }
        else if(operations[i]=="D 1"&&pq.empty()==false){
            priority_queue<int> q1;
            while(!pq.empty()){
                q1.push(pq.top());
                pq.pop();
            }
            q1.pop();
            while(!q1.empty()){
                pq.push(q1.top());
                q1.pop();
            }
        }
        else{
            if(pq.empty()==false){
                pq.pop();
            }
        }
    }
    if(pq.empty()==false){
        int max=pq.top();
        while(pq.size()>1){
                pq.pop();
        }
        answer.push_back(pq.top());
        answer.push_back(max);
    }
    else{
        answer.push_back(0);
        answer.push_back(0);
    }
    
    return answer;
}
