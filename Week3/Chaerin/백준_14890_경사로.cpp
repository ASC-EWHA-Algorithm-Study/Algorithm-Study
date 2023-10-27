
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int N,L;
    int answer=0;
    int arr[101][101];
    cin>>N>>L;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>arr[i][j];
        }
    }
    int used[101][101]={0,};
    for(int i=0;i<N;i++){
        int p=arr[i][0];
        bool plus=true;
        for(int j=1;j<N;j++){
            int n= arr[i][j];
            if(abs(p-n)>1){plus=false;break;}
            else if(p-n==-1){
                for(int h=0;h<L;h++){
                    if(j-h-1>=0){
                        if(arr[i][j-h-1]!=p||used[i][j-h-1]!=0)plus=false;
                        used[i][j-h-1]=1;
                    }
                }
            }
            else if(p-n==1){
                for(int h=0;h<L;h++){
                    if(j+h<N){
                        if(arr[i][j+h]!=n||used[i][j+h]!=0)plus=false;
                        used[i][j+h]=1;
                    }
                }
            }
            p=n;
            if(!plus)break;
        }
        if(plus)answer++;
    }
    int used2[101][101]={0,};
    for(int i=0;i<N;i++){
        int p=arr[0][i];
        bool plus=true;
        for(int j=1;j<N;j++){
            int n= arr[j][i];
            if(abs(p-n)>1){plus=false;break;}
            else if(p-n==-1){
                for(int h=0;h<L;h++){
                    if(j-h-1>=0){
                        if(arr[j-h-1][i]!=p||used2[j-h-1][i]!=0)plus=false;
                        used2[j-h-1][i]=1;
                    }
                }
            }
            else if(p-n==1){
                for(int h=0;h<L;h++){   
                    if(j+h<N){
                        if(arr[j+h][i]!=n||used2[j+h][i]!=0)plus=false;
                        used2[j+h][i]=1;
                    }
                }
            }
            if(!plus)break;
            p=n;
        }
        if(plus)answer++;
    }
    
    cout<<answer;

    return 0;
}
