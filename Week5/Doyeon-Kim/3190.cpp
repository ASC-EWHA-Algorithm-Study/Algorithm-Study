#include <iostream>
#include <queue>

using namespace std;

bool checkRange(int x, int y, int n) {
    return x>=1 && x<=n && y>=1 && y<=n;
}

bool checkSnake(int x, int y, deque<pair<int,int> > q) {
    int n=q.size();
    pair<int, int> p;

    while(n--) {
        p=q.front();
        q.pop_front();
        q.push_back(p);

        if(p.first==x && p.second==y) {
            return false;
        }
    }
    return true;
}


int main() {
    int map[101][101];
    int n, k, x, y, l, t;
    char d;
    queue<pair<int, int> > c;
    deque<pair<int, int> > q;

    cin >> n;
    cin >> k;
    while(k--) {
        cin >> x >> y;
        map[y][x]=1;
    }

    cin >> l;
    while(l--) {
        cin >> t >> d;
        c.push(make_pair(t, d));
    }

    int dx[4]={1,0,-1,0};
    int dy[4]={0,1,0,-1};
    int next_x, next_y;
    int time=0;
    int idx=0;

    q.push_back(make_pair(1,1));
    pair<int, int> p;

    while(1) {
        if(!c.empty() && time==c.front().first) {
            if(c.front().second=='D') {
                idx = (idx+1)%4;
            } else {
                idx = (idx+3)%4;
            }
            c.pop();
        }

        p=q.back();
        next_x=p.first+dx[idx];
        next_y=p.second+dy[idx];

        //벽에 닿거나
        if(!checkRange(next_x, next_y, n)) {
            break;
        }
        //몸에 닿으면
        if(!checkSnake(next_x, next_y, q)) {
            break;
        }

        //사과 있으면
        if(map[next_x][next_y]==1) {
            map[next_x][next_y]=0;
        } else {
            //없으면
            q.pop_front();
        }

        q.push_back(make_pair(next_x, next_y));
        time++;
    }

    cout << time+1;

    return 0;
}

//c++ 음수 인덱스 안됨
//정수 bool 값으로 쓰지 말자~