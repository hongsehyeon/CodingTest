#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int solution(int k, vector<int> tangerine) {
	int answer = 0;
	vector<pair<int, int>> v;
	sort(tangerine.begin(), tangerine.end());
	for (int i = 0; i < tangerine.size(); i++) {
		int v1 = lower_bound(tangerine.begin(), tangerine.end(), tangerine[i]) - tangerine.begin();
		int v2 = lower_bound(tangerine.begin(), tangerine.end(), tangerine[i] + 1) - tangerine.begin();
		if (v2 - v1 != 0)
			v.push_back({ v2 - v1, tangerine[i]});
		i = v2 - 1;
	}
	sort(v.begin(), v.end(), [](pair<int, int> v1, pair<int, int> v2) { return v1.first > v2.first; });
	for (auto& p : v) {
		k -= p.first;
		answer++;
		if (k <= 0)
			break;
	}
	return answer;
}