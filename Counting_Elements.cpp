class Solution
{
public:
    int countElements(vector<int> &arr)
    {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        map<int, int> mymap;
        int i;
        int n = arr.size();

        for (i = 0; i < n; ++i)
        {
            if (mymap.find(arr[i]) == mymap.end())
                mymap[arr[i]] = 1;
            else
                mymap[arr[i]] += 1;
        }

        int count = 0;
        auto itr = mymap.begin();
        ++itr;
        for (; itr != mymap.end(); ++itr)
        {
            auto finder = mymap.find(itr->first - 1);
            if (finder != mymap.end())
                count += finder->second;
        }

        return count;
    }
};