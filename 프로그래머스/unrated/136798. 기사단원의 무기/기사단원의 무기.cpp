#include <iostream>
#include <math.h>
using namespace std;

int solution(int number, int limit, int power) {
	int answer = 1;
	for (int i = 2; i <= number; i++) {
		int cnt = 2;
		for (int j = 2; j <= (int)sqrt(i); j++)
			if (i % j == 0) {
				cnt++;
				if (j * j < i) cnt++;
			}
		answer += cnt > limit ? power : cnt;
	}
	return answer;
}