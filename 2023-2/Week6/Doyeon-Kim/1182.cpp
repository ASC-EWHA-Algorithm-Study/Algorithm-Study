#include <iostream>

using namespace std;

int nums[20];
int result=0;
int n, s;

void backtracking(int idx, int sum) {
    if(idx==n) {
        if (sum == s) {
            result++;
        }
        return;
    }

    backtracking(idx+1, sum);
    backtracking(idx+1, sum+nums[idx]);
}

int main() {
    cin >> n >> s;

    for(int i=0; i<n; i++) {
        cin >> nums[i];
    }

    backtracking(0, 0);
    if(s==0) {
        result--;
    }
    cout << result;

    return 0;
}