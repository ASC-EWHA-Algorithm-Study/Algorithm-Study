#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    cout<<nums[1];
    int pocketmon[200001]={0,};
    
    int size=nums.size();
    
    for(int i=0;i<size;i++){
        pocketmon[nums[i]]++;
    }

    for(int j=0;j<200000;j++){
        if(pocketmon[j]!=0)answer++;
    }
    if(size/2<answer)answer=size/2;

    return answer;
}
