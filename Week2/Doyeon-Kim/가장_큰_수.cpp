#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const int &a, const int &b) {
    string a2=to_string(a);
    string b2=to_string(b);

    return a2+b2>b2+a2;
}

string solution(vector<int> numbers) {
    string answer = "";
    sort(numbers.begin(), numbers.end(), compare);

    if(numbers[0]==0) {
        answer+="0";
    } else {
        for(int i=0; i<numbers.size(); i++) {
            answer+=to_string(numbers[i]);
        }
    }

    return answer;
}

//     잘못 구현한 compare 함수
//     int len=max(a2.size(), b2.size());

//     if(a2.size()<b2.size()) {
//         for(int i=0; i<b2.size()-a2.size(); i++) {
//             a2+=a2[a2.size()-1];
//         }
//     } 

//     if(a2.size()>b2.size()) {
//         for(int i=0; i<a2.size()-b2.size(); i++) {
//             b2+=b2[b2.size()-1];
//         }
//     }

//     for(int i=0; i<len; i++) {
//         if(a2[i]==b2[i]) {
//             continue;
//         } else {
//             return a2[i]>b2[i];
//         }
//     }
//     return a2.size()>b2.size();

//길이 다른 숫자 각각 비교하면 뒤에 어떤 수가 연결될 지 모르기 때문에 정확하게 정렬 불가능
//두 숫자 연결하고 그 값끼리 비교해야 정확하게 정렬할 수 있다