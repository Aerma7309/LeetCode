/*
 * @lc app=leetcode id=844 lang=cpp
 *
 * [844] Backspace String Compare
 */

// @lc code=start
class Solution {
public:
    // bool backspaceCompare(string S, string T)
    // {
    //     stack<char> s, t;
    //     for (auto &i : S)
    //     {
    //         if (i == '#' and !s.empty())
    //             s.pop();
    //         else if (i != '#')
    //             s.push(i);
    //     }
    //     for (auto &i : T)
    //     {
    //         if (i == '#' and !t.empty())
    //             t.pop();
    //         else if (i != '#')
    //             t.push(i);
    //     }
    //     if (s.size() == t.size())
    //     {
    //         int size = s.size();
    //         for (int i = 0; i < size; i++)
    //         {
    //             if (s.top() == t.top())
    //             {
    //                 s.pop();
    //                 t.pop();
    //             }
    //             else
    //                 return false;
    //         }
    //     }
    //     else
    //         return false;
    //     return true;
    // }

    bool backspaceCompare(string S, string T)
    {
        auto dec = [](int &i) {if(i>0) i--; };
        int i, j, size;
        for (i = 0, j = 0, size = S.size(); j < size; j++)
            if (S[j] == '#')
                dec(i);
            else
                S[i] = S[j], i++;
        S.resize(i);
        for (i = 0, j = 0, size = T.size(); j < size; j++)
            if (T[j] == '#')
                dec(i);
            else
                T[i] = T[j], i++;
        T.resize(i);
        return S == T;
    }
};
// @lc code=end

