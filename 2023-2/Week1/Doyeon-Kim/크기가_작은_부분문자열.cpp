#include <string>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    int p_len = p.size();
    string tmp;

    for(int i=0; i<t.size()-p_len+1; i++) {
        tmp="";
        for(int j=0; j<p_len; j++) {
            tmp+=t[j+i];
        }
        if(tmp<=p) {
            answer++;
        }
    }

    return answer;
}