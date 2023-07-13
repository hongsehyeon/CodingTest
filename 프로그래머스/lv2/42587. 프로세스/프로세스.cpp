#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> priorities, int location) {
    queue<pair<int, int>> os;
    for (int i = 0; i < priorities.size(); i++)
        os.push({ priorities[i], i });
    sort(priorities.begin(), priorities.end(), greater<int>());
    int max = 0;
    while (!os.empty()) {
        auto& process = os.front();
        os.pop();
        if (process.first == priorities[max]) {
            max++;
            if (process.second == location)
                break;
        }
        else os.push(process);
    }
    return max;
}