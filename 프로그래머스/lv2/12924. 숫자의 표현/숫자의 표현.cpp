#include <iostream>
using namespace std;

int solution(int n) {
    int answer = 0;
    for (int i = 2; i < n; i++)
        if (!(n % i) && i & 1)
            answer++;
    answer += n & 1 ? 2 : 1;
    return n != 1 ? answer : 1;
}