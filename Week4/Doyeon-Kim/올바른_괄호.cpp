#include<string>
#include <iostream>
#include <queue>

using namespace std;

bool solution(string s)
{
    queue<char> q;

    for(int i=0; i<s.size(); i++) {
        if(s[i]=='(') {
            q.push('(');
        }
        if(s[i]==')') {
            if(!q.empty()) {
                q.pop();
            } else {
                return false;
            }
        }
    }

    return q.empty();
}