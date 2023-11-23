#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string result;
int global_n;
int global_m;
int global_r;
int global_c;
int global_k;

void backtracking(int x, int y, int count, string tmp) {
    //값 찾은 경우거나, 남은 횟수 안에 목적지까지 이동 불가능하면 탈출
    if(!result.empty() || abs(x-global_r)+abs(y-global_c)>global_k-count) {
        return;
    }
    if(count==global_k) {
        if(x==global_r && y==global_c) {
            result=tmp;
        }
        return;
    }
    //아래로
    if(x<global_n) {
        backtracking(x+1, y, count+1,tmp+"d");
    }
    //왼쪽으로
    if(y>1) {
        backtracking(x, y-1, count+1,tmp+"l");
    }
    //오른쪽으로
    if(y<global_m) {
        backtracking(x, y+1, count+1,tmp+"r");
    }
    //위로
    if(x>1) {
        backtracking(x-1, y, count+1,tmp+"u");
    }
}

string solution(int n, int m, int x, int y, int r, int c, int k) {
    string answer;
    global_n=n;
    global_m=m;
    global_r=r;
    global_c=c;
    global_k=k;

    int distance=abs(x-r)+abs(y-c);

    if((distance-k)%2!=0 || distance>k) {
        answer="impossible";
    } else {
        backtracking(x, y, 0, "");
        answer=result;
    }

    return answer;
}

//백트래킹 DFS
//시간 초과 되지 않게 탈출 조건 잘 세워야 함