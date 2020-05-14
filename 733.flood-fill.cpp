// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem733.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode id=733 lang=cpp
 *
 * [733] Flood Fill
 */

// @lc code=start
class Solution
{
public:
    void dfs(vector<vector<int>> &image, int r, int c, int sr, int sc, int newColor, int oldColor)
    {
        if (sr < 0 or sc < 0 or sr > r or sc > c)
            return;
        if (image[sr][sc] == newColor or image[sr][sc] != oldColor)
            return;
        image[sr][sc] = newColor;
        dfs(image, r, c, sr + 1, sc, newColor, oldColor);
        dfs(image, r, c, sr, sc + 1, newColor, oldColor);
        dfs(image, r, c, sr - 1, sc, newColor, oldColor);
        dfs(image, r, c, sr, sc - 1, newColor, oldColor);
    }
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        if (image.empty() or image[0].empty())
            return image;
        dfs(image, image.size() - 1, image[0].size() - 1, sr, sc, newColor, image[sr][sc]);
        return image;
    }
};
// @lc code=end
