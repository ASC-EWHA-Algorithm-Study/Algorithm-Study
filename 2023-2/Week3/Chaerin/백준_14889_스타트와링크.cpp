#include <iostream>
#include <algorithm>
using namespace std;

int team[20][20];
bool check[21];
int N;
int answer=100000000;

void dfs(int now, int cnt){
    if(cnt==(N/2)){
        int start=0, link=0;
    
		for (int i = 0; i < N; i++){
			for (int j = 0; j < N; j++){
				if (check[i] == true && check[j] == true) start += team[i][j];
				if (check[i] == false && check[j] == false) link += team[i][j];
			}
		}
		
		if(answer>abs(start-link))answer=abs(start-link);
		return;
    }
    for(int i=now+1;i<N;i++){
        check[i]=true;
        dfs(i,cnt+1);
        check[i]=false;
    }
}

int main()
{
    cin>>N;

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++) cin>>team[i][j];
    }
    
    dfs(-1,0); 

    cout<<answer;
    return 0;
}
