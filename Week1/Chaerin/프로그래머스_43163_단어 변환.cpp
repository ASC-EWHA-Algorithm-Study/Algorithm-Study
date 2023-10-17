#include <string>
#include <vector>
#include <iostream>
#include <stdbool.h>

using namespace std;

int dis(vector<string> words,vector<int> visited,string target,string now){
    if(target==now)return 0;
    
    int n=words.size();
    int s=target.size();
    
    int ans=1000;
    for (int i=0;i<n;i++){
        if(visited[i]==0){
            int if_nei=0;
            for(int j=0;j<s;j++){
                if(words[i][j]!=now[j])if_nei++;
            }
            if(if_nei==1) {
                visited[i]=1;
                int a=dis(words,visited,target,words[i]);
                if(a!=-1) ans=min(ans,a+1); 
                visited[i]=0;
            }
        }
    }
    if(ans!=1000)return ans;
    return -1;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    vector<int> visited(words.size(),0);
    answer=dis(words,visited,target,begin);
    if (answer==-1) return 0;
    return answer;
}
