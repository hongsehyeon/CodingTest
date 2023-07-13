#include <string>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

int solution(int n) {
    int answer = 0;
	string threeN = "";

	while (n != 0) {
		threeN += to_string(n % 3);
		n /= 3;
	}

	reverse(threeN.begin(), threeN.end());

	for (int i = 0; i < threeN.size(); i++)
		answer += (threeN[i] - '0') * pow(3, i);

    return answer;
}