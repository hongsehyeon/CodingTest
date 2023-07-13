#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    map<char, int> m;
    for (int i = 0; i < s.size(); i++) {
        if (m.count(s[i]) == 0) {
            answer.push_back(-1);
            m.insert(pair<char, int>(s[i], i));
        }
        else {
            answer.push_back(i - m[s[i]]);
            m[s[i]] = i;
        }        
    }
    return answer;
}