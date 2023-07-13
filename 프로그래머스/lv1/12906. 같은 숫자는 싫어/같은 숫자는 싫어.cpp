#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer(1, arr[0]);
    for (auto& v : arr)
        if (answer[answer.size() - 1] != v)
            answer.push_back(v);
    return answer;
}