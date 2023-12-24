#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    int length=sequence.size();
    pair<int, int> p=make_pair(0,0);
    int s_idx=0;
    int e_idx=0;
    int sum=0;

    while(e_idx<=length && s_idx<=length) {
        if(sum<k) {
            sum+=sequence[e_idx];
            e_idx++;
        }
        if(sum>=k) {
            if(sum==k) {
                if((e_idx-s_idx)!=(p.second-p.first)) {
                    p=make_pair(s_idx, e_idx);
                }
            }
            sum-=sequence[s_idx];
            s_idx++;
        }
    }

    answer.push_back(p.first);
    answer.push_back(p.second-1);

    return answer;
}

//투포인터