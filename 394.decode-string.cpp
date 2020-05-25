/*
 * @lc app=leetcode id=394 lang=cpp
 *
 * [394] Decode String
 */

// @lc code=start
class Solution
{
public:
    // string decodeString(string &s, int &i)
    // {
    //     string Ans="";
    //     while (i < s.size() and s[i] != ']')
    //     {
    //         if (isdigit(s[i]))
    //         {
    //             int num = 0;
    //             while (i < s.size() and isdigit(s[i]))
    //                 num = num * 10 + (s[i++] - '0');
    //             i++;//[
    //             string chhotaAns = decodeString(s,i);
    //             i++;//]
    //             while (num--) Ans+=chhotaAns;
    //         }
    //         else Ans+=s[i++];
    //     }
    //     return Ans;
    // }
    // string decodeString(string &s)
    // {
    //     int i = 0;
    //     return decodeString(s, i);
    // }

    string decodeString(string &s)
    {
        stack<string> stkStr;
        stack<int> stkInt;
        string Ans = "";
        int num = 0;
        for (auto &i : s)
        {
            if (isdigit(i))
                num = num * 10 + (i - '0');
            else if (i == '[')
            {
                stkStr.push(Ans);
                stkInt.push(num);
                Ans = "";
                num = 0;
            }
            else if (i == ']')
            {
                string res = stkStr.top();
                int num = stkInt.top();
                stkStr.pop();
                stkInt.pop();
                while (num--)
                    res += Ans;
                Ans = res;
            }
            else
                Ans.push_back(i);
        }
        return Ans;
    }
};
// @lc code=end
