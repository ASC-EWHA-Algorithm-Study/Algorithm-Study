#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N,B,C,n;
    // int A[N];
    vector <int> A;
    cin>>N;
    for(int i=0;i<N;i++){
        // cin>>A[i];
        cin>>n;
        A.push_back(n);
    }
    cin>>B>>C;
    long long answer=N;
    for(int i=0;i<N;i++){
        int a=A[i];
        a-=B;
        if(a>0){
            answer+=a/C;
            if(a%C!=0)answer++;
        }
    }
    
    cout<<answer;
    
    return 0;
}
