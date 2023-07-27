#include <iostream>
#include <numeric>
#include <vector>
#include <set>
using namespace std;

int solution(vector<int> elements) {
	set<int> s;
	for (int i = 1; i <= elements.size() - 1; i++) {
		for (int j = 0; j < elements.size(); j++) {
			int sum = 0;
			for (int k = j; k < j + i; k++)
				sum += elements[k % elements.size()];
			s.insert(sum);
		}
	}
	s.insert(accumulate(elements.begin(), elements.end(), 0, plus<int>()));
	return s.size();
}