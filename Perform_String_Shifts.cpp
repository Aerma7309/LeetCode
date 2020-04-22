class Solution
{
public:
    string stringShift(string s, vector<vector<int>> &shift)
    {
        int r = 0;
        for (auto &i : shift)
        {
            if (i[0])
                r += i[1];
            else
                r -= i[1];
        }
        if (r >= 0)
        {
            r %= s.size();
            s = s.substr(s.length() - r) + s.substr(0, s.length() - r);
        }
        else
        {
            r = (-r) % s.length();
            s = s.substr(r) + s.substr(0, r);
        }
        return s;
    }
};