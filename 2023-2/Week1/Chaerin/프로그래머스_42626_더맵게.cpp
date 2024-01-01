#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    int n=scoville.size();
    priority_queue<int, vector<int>, greater<int> > pq(scoville.begin(), scoville.end());
    
    while(pq.size()>1&&pq.top()<K){
        int first=pq.top();
        pq.pop();
        int second=pq.top();
        pq.pop();
        pq.push(first+second*2);
        answer++;
    }
    if (pq.top()<K) return -1;
//     for(int i=0;i<n;i++){
//         if(scoville[i]>=K) break;
//         scoville[i+1]=scoville[i]+scoville[i+1]*2;
//         scoville[i]=-1;
//         answer++;
//         sort(scoville.begin(),scoville.end());
//     }
//     if(scoville[n-1]<K) return -1;
    
    return answer;
}
