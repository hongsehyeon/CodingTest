#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer(2, 0);
    while (s.size() > 1) {
        answer[1] += count(s.begin(), s.end(), '0');
        s.erase(remove(s.begin(), s.end(), '0'), s.end());
        int num = s.size();
        s.clear();
        while (num != 0) {
            s += num % 2 + '0';
            num /= 2;
        }
        reverse(s.begin(), s.end());
        answer[0]++;
    }
    return answer;
}