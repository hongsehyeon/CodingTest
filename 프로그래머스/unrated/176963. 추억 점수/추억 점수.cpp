#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    map<string, int> m;
    for (int i = 0; i < name.size(); i++) m[name[i]] = yearning[i];
    for (auto& p : photo) {
        int score = 0;
        for (auto& n : p) score += m[n];
        answer.push_back(score);
    }
    return answer;
}