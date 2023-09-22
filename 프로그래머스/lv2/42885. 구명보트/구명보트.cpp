#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int solution(vector<int> people, int limit) {
    sort(people.begin(), people.end());
    int answer = 0, i = 0;
    while (people.size() > i) {
        int back = people.back();
        people.pop_back();
        if (people[i] + back <= limit) {
            answer++;
            i++;
        }
        else answer++;
    }
    return answer;
}