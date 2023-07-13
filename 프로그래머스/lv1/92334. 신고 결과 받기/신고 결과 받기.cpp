#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    map<string, vector<string>> reportMap;
    map<string, int> mailCountMap;

    for (int i = 0; i < id_list.size(); i++) {
        reportMap.insert(pair<string, vector<string>>(id_list[i], {}));
        mailCountMap.insert(pair<string, int>(id_list[i], 0));
    }

    for (int i = 0; i < report.size(); i++) {
        string defendant = report[i].substr(report[i].find(" ") + 1);
        if (count(reportMap[defendant].begin(), reportMap[defendant].end(), report[i]) == 0) 
            reportMap[defendant].push_back(report[i]);
    }

    for (int i = 0; i < id_list.size(); i++) {
        if (reportMap[id_list[i]].size() >= k) {
            for (int j = 0; j < reportMap[id_list[i]].size(); j++) {
                string reporter = reportMap[id_list[i]][j].substr(0, reportMap[id_list[i]][j].find(" "));
                mailCountMap[reporter]++;
            }
        }
    }
    
    for (int i = 0; i < id_list.size(); i++)
        answer.push_back(mailCountMap[id_list[i]]);

    return answer;
}