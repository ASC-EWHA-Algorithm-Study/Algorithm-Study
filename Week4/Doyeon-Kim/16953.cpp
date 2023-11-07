#include <iostream>

using namespace std;

int main() {
    int a, b;
    int cnt=1;
    cin >> a >> b;

    //나머지 1 될 때까지 계속 나눔
    while(true) {
        //정답 찾거나
        if(b==a) {
            break;
            //더이상 만들 수 없는 경우 탈출
        } else if((b%2!=0 && b%10!=1) || b<a) {
            cnt=-1;
            break;
        }
        //2 곱하거나 1 더하는 경우 한 번에 하나만 시행되도록 if else로 처리
        if(b%2==0) {
            b=b/2;
            cnt++;
        } else if(b%10==1) {
            b=b/10;
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}
