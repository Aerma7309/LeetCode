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

class Solution
{
public:
    /**
     * @param intervals: an array of meeting time intervals
     * @return: if a person could attend all meetings
     */
    bool canAttendMeetings(vector<Interval> &intervals)
    {
        if (intervals.empty())
            return true;
        sort(intervals.begin(), intervals.end(), [](Interval &a, Interval b)
             { return a.start < b.start; });
        int bar = intervals[0].start;
        for (auto &interval : intervals)
        {
            if (bar > interval.start)
                return false;
            else
                bar = interval.end;
        }
        return true;
    }
};