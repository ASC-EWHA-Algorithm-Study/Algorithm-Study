#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

priority_queue<pair<int, int>> pq;
vector<vector<int>> global_users;
vector<int> global_emoticons;

void calc(vector<int> discount) {
    int user=0;
    int price=0;

    for(int i=0; i<global_users.size(); i++) {
        int sum=0;

        for(int j=0; j<discount.size(); j++) {
            if(global_users[i][0]<=discount[j]) {
                sum+=global_emoticons[j]*(100-discount[j])/100;
            }
        }

        //예산보다 비싸면 플러스 가입
        if(sum>=global_users[i][1]) {
            user++;
        } else {
            price+=sum;
        }
    }

    pq.push(make_pair(user, price));
}

void backtracking(vector<int> discount, int idx) {
    if(idx==discount.size()) {
        calc(discount);
        return;
    }

    for(int i=10; i<=40; i+=10) {
        discount[idx] = i;
        backtracking(discount, idx + 1);
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;

    global_users=users;
    global_emoticons=emoticons;

    vector<int> discount(emoticons.size());
    backtracking(discount, 0);

    answer.push_back(pq.top().first);
    answer.push_back(pq.top().second);

    return answer;
}