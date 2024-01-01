#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int N,K;
    cin>>N>>K;
    int ran[N+1];
    for(int i=0;i<N;i++){
        cin>>ran[i];
    }
    sort(ran,ran+N);
    long long start=1;
    long long end=ran[N-1];
    long long result=0;
    while(start<=end){
        long long  mid=(start+end)/2;
        int cnt=0;
        for(int i=0;i<N;i++){
            if(ran[i]>=mid) cnt+=ran[i]/mid;
        }
        if(cnt>=K){
            start=mid+1;
            result=mid;
        }
        else{
            end=mid-1;
        }
    }
    cout<<result;
    

    return 0;
}
