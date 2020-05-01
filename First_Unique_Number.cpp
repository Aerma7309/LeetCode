class FirstUnique
{
public:
    list<int> l;
    map<int, list<int>::iterator> ml;
    map<int, int> m;

    void add(int i)
    {
        if (m.find(i) == m.end())
        {
            l.push_back(i);
            m[i]++;
            ml[i] = (--l.end());
        }
        else
        {
            if (ml.find(i) != ml.end())
            {
                l.erase(ml[i]);
                ml.erase(i);
            }
            m[i]++;
        }
    }
    FirstUnique(vector<int> &nums)
    {
        for (int i : nums)
            add(i);
    }

    int showFirstUnique()
    {
        if (l.empty())
            return -1;
        else
            return l.front();
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */