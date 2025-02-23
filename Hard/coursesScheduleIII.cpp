class Solution {
public:
    struct compare{
        bool operator()(vector<int> a, vector<int> b ) {
            return a[1] < b[1];
        }
    };
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), compare());
        priority_queue<int> maxHeap;
        int currTime = 0;

        for (vector<int> course : courses) {
            int duration = course[0];
            int lastDay = course[1];
            currTime += duration;
            maxHeap.push(duration);
            if (currTime > lastDay) {
                currTime -= maxHeap.top(); 
                maxHeap.pop();
            }
        }
        return maxHeap.size();
    }
};

// https://leetcode.com/problems/course-schedule-iii/
