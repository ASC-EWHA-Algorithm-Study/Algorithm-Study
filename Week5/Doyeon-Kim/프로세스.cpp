#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;

    queue<pair<int,int>> q;
    priority_queue<int> pq;

    for(int i=0; i<priorities.size(); i++) {
        q.push(make_pair(priorities[i],i));
        pq.push(priorities[i]);
    }

    while(!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        q.push(p);


        if(p.first < pq.top()) {
            continue;
        }

        if(p.first==pq.top()) {
            answer++;
            if(p.second==location)
                break;
            else {
                pq.pop();
            }
        }

    }

    return answer;
}