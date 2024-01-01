#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    map<string, int> info;
    int tmp;
    
    for(int i=0; i<name.size(); i++) {
        info[name[i]]=yearning[i];
    }    
        
    for(int i=0; i<photo.size(); i++) {
        tmp=0;
        
        for(int j=0; j<photo[i].size(); j++) {
            tmp+=info[photo[i][j]];
        }
        
        answer.push_back(tmp);
    }
    
    return answer;
}
