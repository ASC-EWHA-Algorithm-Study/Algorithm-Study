#include <string>
#include <vector>
using namespace std;
vector<string> arr = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int solution(string s)
{
    int answer = 0;
    string tmp = "";
    
    for(int i=0;i<s.size();i++){
        if (0<=s[i]-‘0’<=9) answer = answer * 10 + s[i] - '0';
        else tmp.push_back(s[i]);
        for(int j=0;j<=9;j++){
            if (arr[j] == tmp){
                answer = answer * 10 + j;
                tmp = "";
                break ;
            }
        }
    }
    return answer;
}
