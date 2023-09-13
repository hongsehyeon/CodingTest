#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
	int T;
	cin >> T;
	int dx[] = { 1, 0, -1, 0 };
	int dy[] = { 0, 1, 0, -1 };
	for (int t = 0; t < T; t++) {
		int R, C;
		string code;
		cin >> R >> C >> code;
		map<pair<int, int>, char> decodeMap;
		int idx = 0;
		for (int i = 0; i < R; i++)
			for (int j = 0; j < C; j++)
				decodeMap[{i, j}] = code[idx++];
		string decode;
		int idxX = 0, idxY = 0, d = 0;
		for (int i = 0; i < code.size(); i++) {
			decode += decodeMap[{ idxY, idxX }];
			decodeMap[{ idxY, idxX }] = NULL;
			if (decodeMap[{ idxY + dy[d], idxX + dx[d] }] == NULL)
				d = ++d % 4;
			idxX += dx[d];
			idxY += dy[d];
		}
		string msg;
		for (int i = 0; i < decode.size(); i += 5) {
			string s = decode.substr(i, 5);
			if (s.size() == 5) {
				int c = stoi(s, 0, 2) + '@';
				msg += c != '@' ? c : ' ';
			}
		}
		while (msg[msg.size() - 1] == ' ')
			msg.erase(msg.end() - 1);
		cout << msg << endl;
	}
	return 0;
}