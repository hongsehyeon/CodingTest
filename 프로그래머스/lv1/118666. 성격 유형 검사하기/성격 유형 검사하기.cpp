#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

string solution(vector<string> survey, vector<int> choices) {
	string answer = "";
	map<char, int> typeToId{ {'R', 0}, {'T', 1}, {'C', 2}, {'F', 3}, {'J', 4}, {'M', 5}, {'A', 6}, {'N', 7} };
	map<int, char> idToType{ {0, 'R'}, {1, 'T'}, {2, 'C'}, {3, 'F'}, {4, 'J'}, {5, 'M'}, {6, 'A'}, {7, 'N'} };
	int counts[] = { 0, 0, 0, 0, 0, 0, 0, 0 };

	for (int i = 0; i < survey.size(); i++) {
		if (choices[i] == 4) continue;
		if (choices[i] < 4) counts[typeToId[survey[i][0]]] -= choices[i] - 4;
		else counts[typeToId[survey[i][1]]] += choices[i] - 4;
	}

	for (int i = 0; i < 8; i += 2)
		answer += counts[i] == counts[i + 1] ? min(idToType[i], idToType[i + 1]) : counts[i] > counts[i + 1] ? idToType[i] : idToType[i + 1];
	
	return answer;
}