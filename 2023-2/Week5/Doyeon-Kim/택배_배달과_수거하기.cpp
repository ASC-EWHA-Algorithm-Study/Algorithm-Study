#include <vector>
#include <algorithm>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    int current=pickups.size()-1;
    int go_idx=current;
    int back_idx=current;

    while(current>=0) {
        int go=0;
        int back=0;

        while(go_idx>=0 && go<=cap) {
            if(deliveries[go_idx]<=(cap-go)) {
                go+=deliveries[go_idx];
                go_idx--;
            } else {
                deliveries[go_idx]-=(cap-go);
                go=cap;
                break;
            }
        }

        while(back_idx>=0 && back<=cap) {
            if(pickups[back_idx]<=(cap-back)) {
                back+=pickups[back_idx];
                back_idx--;
            } else {
                pickups[back_idx]-=(cap-back);
                back=cap;
                break;
            }
        }

        if(go!=0 || back!=0) {
            answer+=(long long)(current+1)*2;
        }
        current=max(go_idx, back_idx);
    }

    return answer;
}

//lv2...