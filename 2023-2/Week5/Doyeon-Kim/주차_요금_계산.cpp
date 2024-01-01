#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <cmath>

using namespace std;

int getCost(vector<int> fees, int time) {
    int cost=fees[1];
    int add=1;

    //올림
    if((time-fees[0])%fees[2]==0) {
        add=0;
    }

    if(time>fees[0]) {
        cost+=((time-fees[0])/fees[2]+add)*fees[3];
    }

    return cost;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string, int> info;
    map<string, int> result;

    for(int i=0; i<records.size(); i++) {
        string hour;
        string min;
        string key;
        int time=0;

        for(int j=0; j<2; j++) {
            hour+=records[i][j];
        }
        time+=60*stoi(hour);

        for(int j=3; j<5; j++) {
            min+=records[i][j];
        }
        time+=stoi(min);

        for(int j=6; j<10; j++) {
            key+=records[i][j];
        }

        if(records[i][11]=='I') {
            info[key]=time;
        } else {
            result[key]+=(time-info[key]);
            info.erase(key);
        }
    }

    for(auto& i : info) {
        result[i.first]+=(1439-i.second);
    }

    for(auto& i : result) {
        answer.push_back(getCost(fees, i.second));
    }

    return answer;
}