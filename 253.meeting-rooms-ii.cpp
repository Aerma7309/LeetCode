/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    /**
     * @param intervals: an array of meeting time intervals
     * @return: the minimum number of conference rooms required
     */
    int minMeetingRooms(vector<Interval> &intervals)
    {
        vector<int> start, end;
        for (auto &interval : intervals)
        {
            start.emplace_back(interval.start);
            end.emplace_back(interval.end);
        }
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        int idx = 0, room = 0, ans = 0;
        for (auto &time : start)
        {
            while (end[idx] <= time)
            {
                idx++;
                room--;
            }
            room++;
            ans = max(ans, room);
        }
        return ans;
    }
};