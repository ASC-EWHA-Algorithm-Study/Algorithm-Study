#include <iostream>
#include <algorithm>

using namespace std;

int max_result = -1000000000;
int min_result = 1000000000;
int nums[12];
int op[4];

void calc(int idx, int n, int result) {
    if(idx==n) {
        max_result=max(max_result, result);
        min_result=min(min_result, result);
        return;
    } else {
        if(op[0]>0) {
            op[0]--;
            calc(idx+1, n, result+nums[idx]);
            op[0]++;
        }
        if(op[1]>0) {
            op[1]--;
            calc(idx+1, n, result-nums[idx]);
            op[1]++;
        }
        if(op[2]>0) {
            op[2]--;
            calc(idx+1, n, result*nums[idx]);
            op[2]++;
        }
        if(op[3]>0) {
            op[3]--;
            calc(idx+1, n, result/nums[idx]);
            op[3]++;
        }
    }
}

int main() {
    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> nums[i];
    }
    for(int i=0; i<4; i++) {
        cin >> op[i];
    }

    calc(1, n, nums[0]);

    cout << max_result << "\n" << min_result;

    return 0;
}