#include <string>
#include <vector>
#include <iostream>
#include <set>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    set<string> s;
    char last = -1;
    for (int i = 0; i < words.size(); i++) {
        string word = words[i];
        if (s.find(word) != s.end() || word[0] != last && i != 0)
            return { i % n + 1, i / n + 1 };
        s.insert(word);
        last = word[word.size() - 1];
    }
    return { 0, 0 };
}