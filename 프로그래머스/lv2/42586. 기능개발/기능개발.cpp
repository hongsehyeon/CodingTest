#include <iostream>
#include <vector>
#include <stack>
#include <cmath>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    stack<int> s;
    for (int i = 0; i < progresses.size(); i++) {
        int day = ceil((100.0 - progresses[i]) / speeds[i]);

        if (s.empty()) {
            s.push(day);
            answer.push_back(1);
        }
        else if (day > s.top()) {
            s.push(day);
            answer.push_back(1);
        }
        else answer.back()++;
    }
    return answer;
}