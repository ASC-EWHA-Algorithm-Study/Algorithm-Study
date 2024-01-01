#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(string s) {
    map<string, string> nums;
    string answer="";
    string key="";

    nums["zero"]="0";
    nums["one"]="1";
    nums["two"]="2";
    nums["three"]="3";
    nums["four"]="4";
    nums["five"]="5";
    nums["six"]="6";
    nums["seven"]="7";
    nums["eight"]="8";
    nums["nine"]="9";

    for(int i=0; i<s.size(); i++) {
        if(s[i]>47 && s[i]<58) {
            answer+=s[i];
        } else {
            key+=s[i];
        }

        if(nums.find(key) != nums.end()) {
            answer+=nums[key];
            key="";
        }
    }

    return stoi(answer);
}