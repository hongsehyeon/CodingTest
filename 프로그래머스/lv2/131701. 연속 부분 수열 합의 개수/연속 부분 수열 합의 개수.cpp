#include <iostream>
#include <vector>
#include <set>
using namespace std;

int solution(vector<int> elements) {
	set<int> s;
	for (int i = 1; i <= elements.size(); i++) {
		int sum = 0;
		for (int j = i; j < i + elements.size(); j++) {
			sum += elements[j % elements.size()];
			s.insert(sum);
		}
	}
	return s.size();
}