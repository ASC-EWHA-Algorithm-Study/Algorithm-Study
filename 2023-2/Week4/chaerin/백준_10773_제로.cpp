#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int main()
{
    stack <int> st;
    int K,a,answer=0;
    cin>>K;
    for(int i=0;i<K;i++){
        cin>>a;
        if(a==0)st.pop();
        else st.push(a);
    }
    while(!st.empty()){
        answer+=st.top();
        st.pop();
    }
    cout<<answer;
    

    return 0;
}
