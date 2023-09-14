#include <iostream>
using namespace std;

int main() {
	int X;
	cin >> X;
	int sum = 0, line = 0;
	while (sum + line < X) {
		sum += line;
		line++;
	}
	int m, n, remain = (X - sum) - 1;
	if (line % 2 == 0) {
		m = 1 + remain;
		n = line - remain;
	}
	else {
		m = line - remain;
		n = 1 + remain;
	}
	cout << m << "/" << n << endl;
	return 0;
}