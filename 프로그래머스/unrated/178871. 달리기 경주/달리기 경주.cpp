#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    vector<string> answer;
    map<string, int> idToRank;
    map<int, string> rankToId;
    for (int i = 0; i < players.size(); i++) {
        idToRank.insert(pair<string, int>(players[i], i));
        rankToId.insert(pair<int, string>(i, players[i]));
    }
    for (int i = 0; i < callings.size(); i++) {
        int rank = idToRank[callings[i]];
        swap(rankToId[rank], rankToId[rank - 1]);
        swap(idToRank[rankToId[rank]], idToRank[rankToId[rank - 1]]);
    }
    for (int i = 0; i < rankToId.size(); i++)
        answer.push_back(rankToId[i]);
    return answer;
}