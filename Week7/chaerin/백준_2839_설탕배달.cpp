
#include <iostream>

using namespace std;

int main()
{
    int N,ans=-1;;
    cin>>N;
    int th=N/3;
    for(int i=0;i<th;i++){
        int temp=N-i*3;
        if(temp%5==0){
            ans=i+temp/5;
            break;
        }
    }
    cout<<ans;
    return 0;
}
