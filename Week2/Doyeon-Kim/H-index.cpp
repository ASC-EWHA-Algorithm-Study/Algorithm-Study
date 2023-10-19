#include <vector>
#include <algorithm>

using namespace std;

//오름차순 정렬
bool compare(const int &a, const int &b) {
    return a>b;
}

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end(), compare);

    for(int i=0; i<citations.size(); i++) {
        if(citations[i]<(i+1)) {
            break;
        } else {
            answer++;
        }
    }

    return answer;
}