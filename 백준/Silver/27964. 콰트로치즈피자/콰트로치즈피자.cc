#include <iostream>
#include <string>
#include <set>
using namespace std;

int main()
{
	int count;
	cin >> count;
	set<string> cheese;
	for (int i = 0; i < count; i++) {
		string topping;
		cin >> topping;
		if (topping.find("Cheese", topping.length() - 6) != string::npos)
			cheese.insert(topping);
	}
	cout << (cheese.size() >= 4 ? "yummy" : "sad");
}