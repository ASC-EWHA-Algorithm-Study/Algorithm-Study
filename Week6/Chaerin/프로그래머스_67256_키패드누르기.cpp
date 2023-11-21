#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>


using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int l=9, r=11;
    int n_y, r_x, r_y, l_x, l_y;
    for(int i=0;i<numbers.size();i++){
        int n=numbers[i]-1;
        if(n==-1)n=10;
        
        if(n==0||n==3||n==6){
            answer+="L";
            l=n;
        }
        else if(n==2||n==5||n==8){
            answer+="R";
            r=n;
        }
        else {
            n_y=n/3;
            r_x= r%3;
            r_y=r/3;
            l_x= l%3;
            l_y=l/3;
      
            int d_r=abs(r_x-1)+abs(r_y-n_y);
            int d_l=abs(l_x-1)+abs(l_y-n_y);

            
            if(d_r<d_l){
                answer+="R";
                r=n;
            }
            else if(d_r==d_l&&hand=="right"){
                answer+="R";
                r=n;
            }
            else{
                answer+="L";
                l=n;
            }

        }
    }
    return answer;
}
