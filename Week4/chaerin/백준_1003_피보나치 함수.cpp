
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int answer_0, answer_1;

int fibonacci(int n) {
    if (n == 0) {
        answer_0++;
        return 0;
    } else if (n == 1) {
        answer_1++;
        return 1;
    } else {
        return fibonacci(n-1) + fibonacci(n-2);
    }
}


int main()
{
    int K,n;
    
    cin>>K;
    for(int i=0;i<K;i++){
        answer_1=0;answer_0=0;
        cin>>n;
        int f=fibonacci(n);
        cout<<answer_0<<" "<<answer_1;
    }

    return 0;
}
