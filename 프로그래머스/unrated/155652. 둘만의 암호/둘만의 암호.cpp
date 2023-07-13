#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(string s, string skip, int index) {
    for (auto& c : s)
    {
        for (int i = 0; i < index; i++)
        {
            c++;
            c = c > 122 ? c % 26 + 78 : c;
            i = count(skip.begin(), skip.end(), c) != 0 ? --i : i;
        }
    }

    return s;
}