#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int num,M,a;
    string N;
    cin>>N;
    cin>>M;
    num=stoi(N);
    
    int gap=num-100;
    if(gap<0)gap*=-1;
    
    vector <int> v;
    for(int i=0;i<10;i++){
        v.push_back(i);
    }
    for(int i=0;i<M;i++){
        cin>>a;
        v.erase(remove(v.begin(), v.end(), a), v.end());
    }

    int answer=N.size();
    for(int i=0;i<N.size();i++){
        // bool exists = find(v, arr + M, move) != arr + M;
        if (!std::count(v.begin(), v.end(), N[i]-'0')){
            int min1 = *min_element(v.begin(), v.end());
	        int max1 = *max_element(v.begin(), v.end());
	        
	        int in=v.size();
	        for(int j=0;j<v.size();j++){
	            if(v[j]>N[i]-'0'){
	                in=j;
	                
	                break;
	            }
	            
	        }
	        
	        int m=v[in-1],M=v[in],now=N[i]-'0';
	        for(int j=i+1;j<N.size();j++){
	            now*=10;
	            now+=N[j]-'0';
	            m*=10;
	            m+=max1;
	            M*=10;
	            M+=min1;
	        }
	        if(N[i]-'0'<min1) answer=M-now+N.size();
	        else if(N[i]-'0'>max1) answer=now-m+N.size();
	        else answer=min(M-now,now-m)+N.size();
	       // cout<<'\n'<<now<<" "<<m<<" "<<M<<"\n";
	        // answer=min(M-now,now-m)+N.size();
	        break;
	        
	        
        }
    }
    cout<<min(answer,gap);
    

    return 0;
}
