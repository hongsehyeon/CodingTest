#include <string>
#include <vector>
using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0, pos = 0;
    string str = "";

    for (auto x : ingredient) {
        char c = x + '0';
        str += c;
    }

    while (true) {
        size_t ret = str.find("1231", pos);
        if (ret == std::string::npos) break;
        str.erase(ret, 4);
        if (ret > 2) pos = ret - 3;
        answer++;
    }

    return answer;
}