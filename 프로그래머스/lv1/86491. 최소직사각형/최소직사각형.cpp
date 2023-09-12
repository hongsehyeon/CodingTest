#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int solution(vector<vector<int>> sizes) {
	int maxX = 0, maxY = 0;
	for (auto& size : sizes) {
		if (size[0] < size[1]) {
			int temp = size[1];
			size[1] = size[0];
			size[0] = temp;
		}
		maxX = maxX < size[0] ? size[0] : maxX;
		maxY = maxY < size[1] ? size[1] : maxY;
	}
	return maxX * maxY;
}