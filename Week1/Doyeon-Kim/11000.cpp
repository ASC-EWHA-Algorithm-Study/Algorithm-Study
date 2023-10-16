#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

//끝나는 시간 기준 내림차순으로 정렬
bool compare(const pair<int, int> &a, const pair<int, int> &b)
{
    //같으면 시작하는 시간 빠른 애 앞에 두기
    if (a.first == b.first)
    {
        return a.second < b.second;
    }
    return a.first < b.first;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, s, t;
    cin >> n;

    vector<pair<int, int> > times;
    vector<int > end;
    //종료 시간 저장하는 최소힙
    //제일 빨리 끝나는 시간이 탑으로 감
    priority_queue<int, vector<int>, greater<int> > q;

    for(int i=0; i<n; i++) {
        cin >> s >> t;
        times.push_back(make_pair(s, t));
    }

    //빨리 시작하는 애들 순으로 정렬
    //최소힙 때문에 어차피 빨리 끝나는 애 먼저 고려하게 되어있음
    sort(times.begin(), times.end(), compare);

    //빨리 사작하는 애부터 고려하면서 최소힙에 저장된 제일 빠른 종료시간이랑 비교
    for(int i=0; i<n; i++) {
        if(!q.empty() && q.top()<=times[i].first) {
            //큐 탑에 강의실 중 제일 빨리 끝나는 애 들어있음 여기에 연결 못 하면 어차피 다른 애들한테도 연결 못함
            //탑 빼고 새로운 애 종료 시간 넣어줌
            q.pop();
        }
        q.push(times[i].second);
    }

    cout << q.size();

    return 0;
}