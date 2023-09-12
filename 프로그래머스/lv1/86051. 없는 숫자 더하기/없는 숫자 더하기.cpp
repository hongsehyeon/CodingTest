#include <vector>
using namespace std;

int solution(vector<int> numbers) {
	int sum = 0;
	for (auto& num : numbers)
		sum += num;
	return 45 - sum;
}