#include <string>
#include <vector>
#include <regex>
#include <algorithm>
using namespace std;

string solution(string new_id) {
	for (auto& c : new_id) c = tolower(c);
	new_id = regex_replace(new_id, regex("[^a-z0-9-_.]+"), "");

	for (int i = 0; i < new_id.size() - 1; i++)
		if (new_id[i] == '.' && new_id[i + 1] == '.')
			new_id.erase(new_id.begin() + i--);

	if (new_id[0] == '.') new_id.erase(new_id.begin());
	if (new_id[new_id.size() - 1] == '.') new_id.erase(new_id.end() - 1);
	if (new_id.empty()) new_id = "a";

	new_id = new_id.substr(0, 15);
	if (new_id[new_id.size() - 1] == '.') new_id.erase(new_id.end() - 1);

	while (new_id.size() <= 2)
		new_id += new_id[new_id.size() - 1];

	return new_id;
}