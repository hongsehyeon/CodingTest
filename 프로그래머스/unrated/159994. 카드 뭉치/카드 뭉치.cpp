#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    int index1 = 0;
    int index2 = 0;

    for (int i = 0; i < goal.size(); i++)
    {
        if (cards1[index1].compare(goal[i]) == 0)
        {
            index1 = index1 + 1 < cards1.size() ? ++index1 : index1;
            continue;
        }

        if (cards2[index2].compare(goal[i]) == 0)
        {
            index2 = index2 + 1 < cards2.size() ? ++index2 : index2;
            continue;
        }

        return "No";
    }

    return "Yes";
}