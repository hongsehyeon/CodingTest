#include <string>
#include <vector>
using namespace std;

long long solution(int n) {
    long long a = 0, b = 1;
    for (int i = 0; i < n; i++) {
        int temp = a % 1234567;
        a = b % 1234567;
        b = (temp + b) % 1234567;
    }
    return b;
}