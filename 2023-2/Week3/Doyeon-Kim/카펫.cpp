#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;

    for (int i = 1; i <= yellow; i++) {
        if ((yellow % i) == 0 && (i + 1 + yellow / i + 1) * 2 == brown) {
            answer.push_back(max(i, yellow / i) + 2);
            answer.push_back(min(i, yellow / i) + 2);
            break;
        }
    }

    return answer;
}