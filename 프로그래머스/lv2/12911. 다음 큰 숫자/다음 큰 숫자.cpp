#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int solution(int n) {
    int next = n;
    string s1;
    while (n != 0) {
        s1 += n % 2 + '0';
        n /= 2;
    }
    while (true) {
        int num = ++next;
        string s2;
        while (num != 0) {
            s2 += num % 2 + '0';
            num /= 2;
        }
        if (count(s1.begin(), s1.end(), '1') == count(s2.begin(), s2.end(), '1'))
            break;
    }
    return next;
}