#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(int a, int b) {
    return a > b;
}



vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> vecsort;

    int n=answers.size();
    // cout<<n;
    int a=0,b=0,c=0;
    
    for(int i=0;i<n;i++){
        if(i%5+1==answers[i])a++;
        if(i%2==0&&answers[i]==2)b++;
        else if(i%8==1&&answers[i]==1)b++;
        else if(i%8==3&&answers[i]==3)b++;
        else if(i%8==5&&answers[i]==4)b++;
        else if(i%8==7&&answers[i]==5)b++;
        if((i%10)/2==0&&answers[i]==3)c++;
        else if((i%10)/2==1&&answers[i]==1)c++;
        else if((i%10)/2==2&&answers[i]==2)c++;
        else if((i%10)/2==3&&answers[i]==4)c++;
        else if((i%10)/2==4&&answers[i]==5)c++;
    }
    vecsort.push_back(a);
    vecsort.push_back(b);
    vecsort.push_back(c);
    // cout<<vecsort[0]<<" "<<vecsort[1]<<" "<<vecsort[2];
    sort(vecsort.begin(),vecsort.end(),cmp);
    if(vecsort[0]==a)answer.push_back(1);
    if(vecsort[0]==b)answer.push_back(2);
    if(vecsort[0]==c)answer.push_back(3);
    
    
    return answer;
}
