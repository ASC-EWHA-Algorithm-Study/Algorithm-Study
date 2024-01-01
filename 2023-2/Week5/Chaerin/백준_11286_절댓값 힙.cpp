#include<iostream>
#include<queue>
#include<cmath>
using namespace std;

struct comp{
	bool operator()(int a, int b)
	{
		if (abs(a) == abs(b))
			return a > b;
		else
			return abs(a) > abs(b);
	}
};

int main()
{
	int n; cin >> n;
	Solution(n);
	priority_queue< int, vector<int>, comp > pq;

	while (n--){
		int c; 
		cin >> c;

		if (c == 0){
			if (pq.empty()){
				cout << '0' << '\n';
			}
			else{
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
		else{
			pq.push(c);
		}
	}

	return 0;
}
