#include <string>
#include <vector>

using namespace std;

int solution(string s) {
	int answer = 0, same = 0;
	char x = s.front();
	for (int i = 0; i < s.size(); i++) {
		same += s[i] == x ? 1 : -1;
		answer += same == 0 ? 1 : 0;
		x = same == 0 ? s[i + 1] : x;
	}
	return same == 0 ? answer : answer + 1;
}