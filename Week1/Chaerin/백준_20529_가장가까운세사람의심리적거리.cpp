#include <iostream>
#include <algorithm>

using namespace std;

int cmp_score(string a, string b){
    int sc=0;
    if(a[0]!=b[0])sc++;
    if(a[1]!=b[1])sc++;
    if(a[2]!=b[2])sc++;
    if(a[3]!=b[3])sc++;
    return sc;
}


int main()
{
    int T,N;
    
    cin>>T;
    for(int t=0;t<T;t++){
        string mbti[100000];
        cin>>N;
        
        for(int i=0;i<N;i++){
            cin>>mbti[i];
        }
        
        int ans=1000;
        if(N>32) ans=0;        // 비둘기집 정리. 개념 정리
        else{
            for(int i=0;i<N-2;i++){
                for(int j=i+1;j<N-1;j++){
                    for(int k=j+1;k<N;k++){
                        int score=0;
                        score+=cmp_score(mbti[i],mbti[j]);
                        score+=cmp_score(mbti[i],mbti[k]);
                        score+=cmp_score(mbti[k],mbti[j]);
                        if (score<ans)ans=score;
                    }
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
