#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer(targets.size());
    int minIndex = 101;
    int cnt = 0;

    for (int i = 0; i < targets.size(); i++)
    {
        cnt = 0;
        for (int j = 0; j < targets[i].size(); j++)
        {
            minIndex = 101;
            for (int k = 0; k < keymap.size(); k++)
            {
                if (count(keymap[k].begin(), keymap[k].end(), targets[i][j]) == 0)
                    continue;
                int index = find(keymap[k].begin(), keymap[k].end(), targets[i][j]) - keymap[k].begin();
                minIndex = min(minIndex, index + 1);
            }

            if (minIndex != 101)
            {
                answer[i] += minIndex;
                cnt++;
            }
            else
                answer[i] = -1;
        }
        answer[i] = answer[i] == 0 || cnt != targets[i].size() ? -1 : answer[i];
    }

    return answer;
}