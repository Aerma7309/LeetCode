/*
 * @lc app=leetcode id=394 lang=cpp
 *
 * [394] Decode String
 */

// @lc code=start
class Solution
{
public:
    // int i = 0;
    string decodeString(string &s, int &i)
    {
        string res = "";
        while (i < s.size() and s[i] != ']')
        {
            if (!isdigit(s[i]))
                res += s[i++];
            else
            {
                int num = 0;
                while (i < s.size() and isdigit(s[i]))
                    num = num * 10 + (s[i++] - '0');
                i++; //[
                string subRes = decodeString(s,i);
                i++; //]
                while (num--)
                    res += subRes;
            }
        }
        return res;
    }

    string decodeString(string &s)
    {
        int i = 0;
        return decodeString(s, i);
    }
};
// @lc code=end
