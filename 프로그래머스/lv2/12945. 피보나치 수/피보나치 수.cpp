#include <iostream>
using namespace std;

int solution(int n) {
    int answer = 0, n1 = 0, n2 = 1;
    for (int i = 2; i <= n; i++) {
        answer = (n1 + n2) % 1234567;
        n1 = n2 % 1234567;
        n2 = answer % 1234567;
    }
    return answer;
}