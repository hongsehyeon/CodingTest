#include <iostream>
#include <string>
#include <stack>
using namespace std;

int solution(string s) {
    stack<char> s1;
    for (auto& c : s)
        !s1.empty() && s1.top() == c ? s1.pop() : s1.push(c);
    return s1.empty();
}