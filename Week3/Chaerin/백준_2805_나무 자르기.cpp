#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    long long N,M;
    cin>>N>>M;
    int tree[N];
    for(int i=0;i<N;i++){
        cin>>tree[i];
    }
    sort(tree,tree+N);
    long long start=0;
    long long end=tree[N-1];
    long long result = 0;
    while(start<=end){
        long long mid=(start+end)/2;
        long long amount=0;
        for(int i=0;i<N;i++){
            if(tree[i]>mid)amount+=tree[i]-mid;
        }
        if(amount>=M) {
            start=mid+1;
            result = mid; 
        }
        else end=mid-1;
    }
    cout << result;
    return 0;
}
