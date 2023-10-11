#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    map<string, int> info;
    int index;

    for(int i=0; i<players.size(); i++) {
        info[players[i]]=i;
    }

    for(int i=0; i<callings.size(); i++) {
        index=info[callings[i]];
        info[players[index-1]]++;
        info[players[index]]--;
        swap(players[index-1], players[index]);
    }

    return players;
}