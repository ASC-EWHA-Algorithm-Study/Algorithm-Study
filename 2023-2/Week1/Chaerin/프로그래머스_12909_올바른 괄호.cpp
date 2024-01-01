#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack <char> st;
    int l=s.size();
    for(int i=0;i<l;i++){
        if(s[i]=='(') st.push('(');
        else{
            if(st.empty()) {st.push(')'); break;}
            else st.pop();
            // 다음과 같이 했을 땐 테스트 18번에서 실패했다. 무슨 차이인지 아직은 잘 모르겠다.
            // if(st.top()=='(') st.pop();
            // else {st.push(')'); break;}
        }
    }
    if(st.empty()) answer=true;
    else answer=false;

    return answer;
}
