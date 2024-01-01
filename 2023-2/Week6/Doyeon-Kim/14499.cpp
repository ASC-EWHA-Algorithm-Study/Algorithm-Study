#include <iostream>

using namespace std;

int map[21][21];
int dice[7]={0,};

bool checkRange(int x, int y, int n, int m) {
    return x>=0 && x<n && y>=0 && y<m;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m,x,y,k,cmd,tmp;

    //동 서 북 남
    int dx[4]={0, 0, -1,1};
    int dy[4]={1,-1,0,0};

    int top=1;
    int up=2;
    int right=3;

    cin >> n >> m >> x >> y >> k;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> map[i][j];
        }
    }

    for(int i=0; i<k; i++) {
        cin >> cmd;

        x+=dx[cmd-1];
        y+=dy[cmd-1];

        if(!checkRange(x,y,n,m)) {
            x-=dx[cmd-1];
            y-=dy[cmd-1];
            continue;
        }

        tmp=top;

        //동
        if(cmd==1) {
            top=(7-right);
            right=tmp;
        }

        //서
        if(cmd==2) {
            top=right;
            right=(7-tmp);
        }

        //북
        if(cmd==3) {
            top=(7-up);
            up=tmp;
        }

        //남
        if(cmd==4) {
            top=up;
            up=(7-tmp);
        }

        if(map[x][y]==0) {
            map[x][y]=dice[7-top];
        } else {
            dice[7-top]=map[x][y];
            map[x][y]=0;
        }
        cout << dice[top] << "\n";
    }

    return 0;
}