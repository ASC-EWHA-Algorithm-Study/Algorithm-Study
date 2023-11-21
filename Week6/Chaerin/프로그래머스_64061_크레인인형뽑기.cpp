#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    stack <int> s;
    int answer = 0;
    int m=board.size();
    for(int i=0;i<moves.size();i++){
        int n=moves[i]-1;
        int temp=0;
        for(int j=0;j<m;j++){
            if(board[j][n]!=0){
                temp=board[j][n];
                cout<<temp<<" ";
                board[j][n]=0;
                if(!s.empty()&&s.top()==temp){s.pop();answer+=2;}
                else s.push(temp);
                break;
            }
        }
    }
    
    return answer;
}
