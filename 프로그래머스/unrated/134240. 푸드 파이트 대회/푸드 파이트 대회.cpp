#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

string solution(vector<int> food) {
	string s1 = "";
	for (int i = 1; i < food.size(); i++) {
		string s(food[i] / 2, i + '0');
		s1 += s;
	}
	string s2(s1);
	reverse(s2.begin(), s2.end());
	return s1 + "0" + s2;
}