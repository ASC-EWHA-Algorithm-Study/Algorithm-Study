#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(const pair<int, float> &a, const pair<int, float> &b) {
    return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<pair<int, float>> fail(N, {0,0});
    float finish=0;
    float trial;

    for(int i=0; i<stages.size(); i++) {
        if(stages[i]!=(N+1)) {
            fail[stages[i]-1].second++;
        } else {
            finish++;
        }
    }

    for(int i=0; i<N; i++) {
        fail[i].first=i+1;
        if(fail[i].second) {
            trial=finish;
            for(int j=N; j>i; j--) {
                trial+=fail[j-1].second;
            }
            fail[i].second/=trial;
        }
    }

    stable_sort(fail.begin(), fail.end(), compare);

    for(int i=0; i<N; i++) {
        answer.push_back(fail[i].first);
    }

    return answer;
}

//sort 함수 쓰면 불안정하다고 함 stable_sort 써야 테케 제대로 통과