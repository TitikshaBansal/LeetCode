class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int i = 0, n = intervals.size();
        while (i < n && intervals[i][1] < newInterval[0]) i++;  
        int start = newInterval[0], end = newInterval[1];
        int mergeStart = i;  
        while (i < n && intervals[i][0] <= newInterval[1]) {
            start = min(start, intervals[i][0]);
            end = max(end, intervals[i][1]);
            i++;  
        }
        intervals.erase(intervals.begin() + mergeStart, intervals.begin() + i);
        intervals.insert(intervals.begin() + mergeStart, {start, end});
        
        return intervals;
    }
};

// https://leetcode.com/problems/insert-interval/
