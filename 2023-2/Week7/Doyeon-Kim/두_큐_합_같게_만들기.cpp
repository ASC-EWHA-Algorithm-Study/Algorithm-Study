#include <string>
#include <vector>
#include <numeric>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer=-1;
    long long queue1_sum=0;
    long long queue2_sum=0;
    int queue1_idx=0;
    int queue2_idx=0;
    int n=queue1.size();

    for(int i=0; i<n; i++) {
        queue1_sum+=queue1[i];
        queue2_sum+=queue2[i];
    }

    long long tmp=queue1_sum-(queue1_sum+queue2_sum)/2;

    while(queue1_idx<2*n && queue2_idx<2*n) {
        if(tmp==0) {
            answer=queue1_idx+queue2_idx;
            break;
        }
        if(tmp>0) {
            tmp-=queue1[queue1_idx];
            queue1_sum-=queue1[queue1_idx];
            queue2.push_back(queue1[queue1_idx]);
            queue1_idx++;
        }
        if(tmp<0) {
            tmp+=queue2[queue2_idx];
            queue1_sum+=queue2[queue2_idx];
            queue1.push_back(queue2[queue2_idx]);
            queue2_idx++;
        }
    }

    return answer;
}