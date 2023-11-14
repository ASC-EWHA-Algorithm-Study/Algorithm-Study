#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<vector<int> > global_minerals;
vector<int> global_picks;
unordered_map<string, int> m= {
        make_pair("diamond", 0),
        make_pair("iron", 1),
        make_pair("stone", 2)
};
int total=0;
int result=100000000;

void backtracking(int idx, int usage, int count) {
    if(idx==global_minerals.size() || count==total) {
        result=min(result, usage);
        return;
    }
    //곡괭이
    for(int i=0; i<3; i++) {
        if(global_picks[i]>0) {
            int tmp=0;
            //광물
            for(int j=0; j<3; j++) {
                if (i<=j) {
                    tmp += global_minerals[idx][j];
                }
                else if (i==(j+1)) {
                    tmp += 5*global_minerals[idx][j];
                }
                else {
                    tmp += 25*global_minerals[idx][j];
                }
            }
            global_picks[i]--;
            backtracking(idx+1, usage + tmp, count+1);
            global_picks[i]++;
        }
    }
}

int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0;

    for(int i=0; i<picks.size(); i++) {
        global_picks.push_back(picks[i]);
        total+=picks[i];
    }

    //다섯개 단위로 쪼갬
    for (int i = 0; i < minerals.size(); i+=5) {
        vector<int> tmp(3,0);
        for (int j = 0; j < 5; j++) {
            if(i+j<minerals.size()) {
                tmp[m[minerals[i+j]]]++;
            }
        }
        global_minerals.push_back(tmp);
    }

    backtracking(0, 0, 0);

    return result;
}