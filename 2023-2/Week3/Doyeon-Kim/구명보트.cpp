#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool compare(int a, int b) {
    return a > b;
}

int solution(vector<int> people, int limit) {
    int answer = 0;
    priority_queue<int> pq;

    sort(people.begin(), people.end(), compare);

    pq.push(limit-people[0]);

    for(int i=1; i<people.size(); i++) {
        if(!pq.empty() && (pq.top()>=people[i])) {
            pq.pop();
            answer++;
        } else {
            pq.push(limit-people[i]);
        }
    }

    return answer+pq.size();
}

//그리디
//pq.top 코드 돌리기 전에 pq.empty 검사 안 하면 에러!! 바보!!
//내림차순+최대힙 최대힙 루트에 연결할 수 없으면 나머지도 전부 연결 못 함 O(1)로 판단 가능