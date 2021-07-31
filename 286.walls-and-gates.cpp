#include <bits/stdc++.h>
using namespace std;
const int INF = 2147483647;
class Solution
{
public:
    /**
     * @param rooms: m x n 2D grid
     * @return: nothing
     */

    void wallsAndGates(vector<vector<int>> &rooms)
    {
        queue<pair<int, int>> q;
        int rows = rooms.size(), cols = rooms[0].size();
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                if (rooms[i][j] == 0)
                    q.push({i - 1, j}), q.push({i + 1, j}), q.push({i, j - 1}), q.push({i, j + 1});
        int depth = 1;
        while (not q.empty())
        {
            int sz = q.size();
            for (int i = 0; i < sz; i++)
            {
                pair<int, int> loc = q.front();
                q.pop();
                if (loc.first >= 0 and loc.second >= 0 and loc.first < rows and loc.second < cols and rooms[loc.first][loc.second] == INF)
                {
                    //loc is valid i.e. is in the grid and is empty room
                    rooms[loc.first][loc.second] = depth;
                    q.push({loc.first - 1, loc.second});
                    q.push({loc.first + 1, loc.second});
                    q.push({loc.first, loc.second - 1});
                    q.push({loc.first, loc.second + 1});
                }
            }
            depth++;
        }
    }
};