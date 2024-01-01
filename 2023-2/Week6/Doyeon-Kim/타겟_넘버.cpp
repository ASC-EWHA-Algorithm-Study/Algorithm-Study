#include <string>
#include <vector>

using namespace std;

int result=0;

void dfs(vector<int> numbers, int target, int index, int sum) {
    if(index==numbers.size()) {
        if(sum==target) {
            result++;
        }
        return;
    }
    dfs(numbers, target, index+1, sum+numbers[index]);
    dfs(numbers, target, index+1, sum-numbers[index]);
}

int solution(vector<int> numbers, int target) {
    dfs(numbers, target, 0, 0);

    return result;
}
//DFS