#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    queue<pair<int, int>> bridge;
    int time = 0, w = 0;
    for (int i = 0; i < truck_weights.size(); i++) {
        time++;
        if (time - bridge.front().second == bridge_length) {
            w -= bridge.front().first;
            bridge.pop();
        }
        while (w + truck_weights[i] > weight) {
            time = bridge.front().second + bridge_length;
            w -= bridge.front().first;
            bridge.pop();
        }
        w += truck_weights[i];
        bridge.emplace(truck_weights[i], time);
    }
    time = bridge.back().second + bridge_length;
    return time;
}