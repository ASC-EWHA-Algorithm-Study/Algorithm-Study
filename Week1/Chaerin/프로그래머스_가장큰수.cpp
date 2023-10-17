#include <string>
#include <vector>
#include <iostream>
#include <algorithm>


using namespace std;


bool cmp (string a, string b){
    if(a[0]==b[0]){
        if(a[1]==b[1]){
            if(a[2]==b[2]){
                return a[3]>b[3];
            }
            else{
                return a[2]>b[2];
            }
        }
        else{
            return a[1]>b[1];
        }
    }
    else{
        return a[0]>b[0];
    }
}

string solution(vector<int> numbers) {
    string answer = "";
    int n=numbers.size();
    
    vector<string> str_num(n); // 크기 지정 안했다가 오류남
    
    for(int i=0;i<n;i++){
        str_num[i]=to_string(numbers[i]);
    }
    
    sort(str_num.begin(),str_num.end(),cmp);
    
    for(int i=0;i<n;i++){
        answer+=str_num[i];
    }
    
    return answer;
}
