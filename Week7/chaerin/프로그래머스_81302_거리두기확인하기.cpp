#include <string>
#include <vector>
#include <iostream>

using namespace std;
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for(int i=0;i<5;i++){
        int ans=1;
        for(int j=0;j<5;j++){
            for(int k=0;k<5;k++){
                // cout<<places[i][j][k];
                if(places[i][j][k]=='P'){
                    for(int l=0;l<4;l++){
                        int nx=j+dx[l];
                        int ny=k+dy[l];
                        cout<<j<<k<<" ";
                        if(nx>=0&&nx<5&&ny>=0&&ny<5){
                            if(places[i][nx][ny]=='P'){
                                // cout<<nx<<ny<<places[i][nx][ny]<<"\n";
                                ans=0;
                                break;
                            }
                            else if(places[i][nx][ny]=='O'){
                                for(int ll=0;ll<4;ll++){
                                    int nx2=nx+dx[ll];
                                    int ny2=ny+dy[ll];
                                    if(nx2==j&&ny2==k)break;
                                    if(nx2>=0&&nx2<5&&ny2>=0&&ny2<5){
                                        if(places[i][nx2][ny2]=='P'){
                                            // cout<<nx<<ny<<places[i][nx][ny]<<"\n";
                                            ans=0;
                                            break;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                
                if(ans==0)break;
            }
            if(ans==0)break;
        }
        answer.push_back(ans);
    }
    
    return answer;
}
