#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int solution(vector<int> number) {
	int answer = 0;
	sort(number.begin(), number.end(), greater<>());
	for (int i = 0; i < number.size() - 2; i++) {
		if (number[i] < 0) break;
		for (int j = i + 1; j < number.size() - 1; j++)
			for (int k = j + 1; k < number.size(); k++)
				if (number[i] + number[j] + number[k] == 0)
					answer++;
	}
	return answer;
}