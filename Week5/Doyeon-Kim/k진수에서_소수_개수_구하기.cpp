#include <string>
#include <vector>
#include <cmath>

using namespace std;

// void isPrime(long long m, vector<bool> &is_prime) {
//     is_prime[0]=is_prime[1]=false;

//     for(long long i=2; i<=sqrt(m); i++) {
//         if(is_prime[i]) {
//             for(long long j=i*i; j<=m; j+=i) {
//                 is_prime[j]=false;
//             }
//         }
//     }
// }

bool isPrime(long long m) {
    if(m==1) {
        return false;
    }
    for(long long i=2; i<=sqrt(m); i++) {
        if(m%i==0) {
            return false;
        }
    }
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    string result="";

    //소수 배열
    //long long m=1000000;
    // vector<bool> is_prime(m, true);
    // isPrime(m, is_prime);

    while(n>=1) {
        result=to_string(n%k)+result;
        n/=k;
    }

    string num="";
    string text=result+"0";

    for(int i=0; i<text.size(); i++) {
        if(text[i]=='0') {
            if(num!="" && isPrime(stol(num))) {
                answer++;
            }
            num="";
        } else {
            num+=text[i];
        }
    }
    return answer;
}