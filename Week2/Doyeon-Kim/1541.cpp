#include <iostream>
#include <vector>

using namespace std;

int main() {
    string input;
    string tmp="";
    int result;
    int sum=0;
    vector<int> nums;

    cin >> input;

    for(int i=0; i<input.size()+1; i++) {
        if(isdigit(input[i])) {
            tmp+=input[i];
        } else {
            //+는 계속 더하다
            sum+=stoi(tmp);
            //-이거나 마지막 숫자 만났을 때만 배열에 추가
            if(input[i]!='+') {
                nums.push_back(sum);
                sum=0;
            }
            tmp="";
        }
    }

    result = nums[0];
    for(int j=1; j<nums.size(); j++) {
        result-=nums[j];
    }
    cout << result;

    return 0;
}
