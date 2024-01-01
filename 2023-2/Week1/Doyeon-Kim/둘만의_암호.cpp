#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    vector<char> alpha1;
    map<char, int> alpha2;
    char tmp='a';
    int idx=0;

    for(int i=0; i<26; i++) {
        if(skip.find(tmp) == std::string::npos) {
            alpha1.push_back(tmp);
            alpha2[tmp]=idx;
            idx++;
        }
        tmp++;
    }

    for(int i=0; i<s.size(); i++) {
        answer+=alpha1[(alpha2[s[i]]+index)%idx];
    }

    return answer;
}