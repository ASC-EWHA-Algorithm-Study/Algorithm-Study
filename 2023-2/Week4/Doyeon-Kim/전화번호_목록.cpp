#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    bool flag;

    sort(phone_book.begin(), phone_book.end());

    for(int i=0; i<phone_book.size()-1; i++) {
        flag = true;
        for(int j=0; j<phone_book[i].size(); j++) {
            if(phone_book[i+1][j]!=phone_book[i][j]) {
                flag = false;
                break;
            }
        }
        if(flag) {
            answer=false;
            break;
        }
    }

    return answer;
}