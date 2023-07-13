#include <string>
#include <vector>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    int today_year = stoi(today.substr(0, 4));
    int today_month = stoi(today.substr(5, 6));
    int today_day = stoi(today.substr(8, 9));
    for (int i = 0; i < privacies.size(); i++) {
        int p_year = stoi(privacies[i].substr(0, 4));
        int p_month = stoi(privacies[i].substr(5, 6));
        int p_day = stoi(privacies[i].substr(8, 9));
        string p_type = privacies[i].substr(11);
        for (auto& t : terms) {
            if (p_type.compare(t.substr(0, 1)) == 0) {
                int t_term = stoi(t.substr(2));
                int month = p_month + t_term;
                p_year += month % 12 == 0 ? month / 12 - 1 : month / 12;
                p_month = month % 12 == 0 ? 12 : month % 12;
                break;
            }
        }
        if (p_year > today_year || p_year == today_year && p_month > today_month || p_year == today_year && p_month == today_month && p_day - 1 >= today_day)
            continue;
        answer.push_back(i + 1);
    }
    return answer;
}