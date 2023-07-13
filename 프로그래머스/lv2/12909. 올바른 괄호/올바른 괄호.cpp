#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool solution(string s) {
    stack<int> parentheses;
    for (auto& c : s)
        c == ')' && !parentheses.empty() && parentheses.top() == '(' ? parentheses.pop() : parentheses.push(c);
    return parentheses.empty();
}