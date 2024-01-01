#include <iostream>

using namespace std;

int backtracking(string word, int s, int e, bool flag) {
    while(s<e) {
        //cout << s << " " << e << endl;
        if(word[s]==word[e]) {
            s++;
            e--;
        } else {
            if(flag) {
                return 2;
            } else if(backtracking(word, s, e-1,true)==0 || backtracking(word, s+1, e,true)==0) {
                return 1;
            } else {
                return 2;
            }
        }
    }
    return 0;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, s, e;
    string word;
    cin >> n;

    while(n--) {
        cin >> word;
        cout << backtracking(word,0,word.size()-1,false) << "\n";
    }

    return 0;
}

//투포인터+백트래킹
//aabaaba 같은 경우 오른쪽 지우는 경우, 왼쪽 지우는 경우 모두 탐색해야 함 -> 백트래킹