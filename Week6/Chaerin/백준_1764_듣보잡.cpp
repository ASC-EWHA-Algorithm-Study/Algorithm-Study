#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N,M;
    vector <string> v;
    map <string,int> m;
    cin>>N>>M;
    string a;
    for(int i=0;i<N;i++){
        cin>>a;
        m[a]++;
    }
    
    for(int i=0;i<M;i++){
        cin>>a;
        if(m[a]>0)v.push_back(a);
    }
    sort(v.begin(),v.end());
    cout<<v.size()<<'\n';
    for(int j=0;j<v.size();j++){
            cout<<v[j]<<'\n';
        }

    return 0;
}
