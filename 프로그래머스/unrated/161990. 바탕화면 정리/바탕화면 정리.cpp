#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> wallpaper) {
    int lux = 51, luy = 51, rdx = -1, rdy = -1;
    
    for (int i = 0; i < wallpaper.size(); i++)
    {
        for (int j = 0; j < wallpaper[i].size(); j++)
        {
            if (wallpaper[i][j] == '#')
            {
                if (lux > i) lux = i;
                if (luy > j) luy = j;
                if (rdx < i) rdx = i;
                if (rdy < j) rdy = j;
            }
        }
    }

    return vector<int>{ lux, luy, rdx + 1, rdy + 1 };
}