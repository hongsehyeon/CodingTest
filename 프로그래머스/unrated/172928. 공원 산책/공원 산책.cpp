#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    int x = 0, y = 0;
    vector<char> op = { 'N', 'S', 'W', 'E' };
    const int deltaX[] = { 0, 0, -1, 1 };
    const int deltaY[] = { -1, 1, 0, 0 };

    for (int i = 0; i < park.size(); i++)
        for (int j = 0; j < park[i].size(); j++)
            if (park[i][j] == 'S') { x = j; y = i; }

    for (int i = 0; i < routes.size(); i++) {
        int opIndex = find(op.begin(), op.end(), routes[i][0]) - op.begin();
        int steps = atoi(routes[i].substr(2).c_str());
        int nextX = x, nextY = y, cnt = 0;
        for (int j = 0; j < steps; j++) {
            nextX += deltaX[opIndex];
            nextY += deltaY[opIndex];
            if (nextX < 0 || nextX >= park[0].size() || nextY < 0 || nextY >= park.size())
                break;
            if (park[nextY][nextX] != 'X')
                cnt++;
        }
        if (cnt == steps) {
            x = nextX;
            y = nextY;
        }
    }
    return { y, x };
}