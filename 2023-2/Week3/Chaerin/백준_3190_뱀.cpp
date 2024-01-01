#include <iostream>
#include <queue>
#include <algorithm>


using namespace std;

int main()
{
    int N,K,L,a,b;
    char c;
    cin>>N;
    cin>>K;
    int board[N+1][N+1]={0,};
    for(int i=0;i<K;i++){
        cin>>a>>b;
        board[a][b]=1;
    }
    cin>>L;
    int Dir[10001]={0,};  //직진은 0 오른쪽 1 왼쪽2
    for(int i=0;i<L;i++){
        cin>>a>>c;
        if(c=='D')Dir[a]=1;
        else if (c=='L')Dir[a]=2;
    }
    
    int dir=1; //오른쪽 1 , 왼쪽2, 위 3, 아래4
    int x=1,y=1;
    board[1][1]=-1;
    int answer=0;
    queue <pair<int,int>> snake;
    snake.push(make_pair(1,1));
    for(int i=0;i<10001;i++){
        // cout<<'\n';
        
        answer++;
        // cout<<'\n'<<answer<<"초\n";
        if(Dir[i]==0){ //직진
            if(dir==1)y++;
            else if(dir==2)y--;
            else if(dir==3)x--;
            else x++;
        }
        else if(Dir[i]==1){
            if(dir==1){x++;dir=4;}
            else if(dir==2){x--;dir=3;}
            else if(dir==3){y++;dir=1;}
            else {y--;dir=2;}
        }
        else{
            if(dir==1){x--;dir=3;}
            else if(dir==2){x++;dir=4;}
            else if(dir==3){y--;dir=2;}
            else {y++;dir=1;}
        }
        // cout<<"\n"<<x<<y<<'\n';
        
        if(x==0||x==N+1||y==0||y==N+1||board[x][y]==-1)break;
        if(board[x][y]==0){ //사과가 아닌 경우
            int end_x=snake.front().first;
            int end_y=snake.front().second;
            snake.pop();
            board[end_x][end_y]=0;
        }
        snake.push(make_pair(x,y));
        board[x][y]=-1;
        // answer++;
        // cout<<'\n'<<answer<<"초\n";
        // for(int j=1;j<N+1;j++){for(int k=1;k<N+1;k++){cout<<board[j][k]<<' ';}cout<<'\n';}
        
    }
    cout<<answer;

    return 0;
}
