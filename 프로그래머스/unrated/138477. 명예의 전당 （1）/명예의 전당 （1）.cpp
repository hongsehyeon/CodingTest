#include <algorithm>
#include <vector>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer, rank;
    for (int i = 0; i < score.size(); i++) {
        rank.push_back(score[i]);
        sort(rank.begin(), rank.end(), greater<int>());
        answer.push_back(rank.size() <= k ? rank[i] : rank[k - 1]);
    }
    return answer;
}