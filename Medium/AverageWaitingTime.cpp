class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size();
        double waiting = customers[0][1];
        int prev = customers[0][0] + customers[0][1];

        for (int ind = 1; ind < n; ++ind) {
            vector<int> times = customers[ind];
            int arrive = times[0];

            int start_cook = max(arrive, prev);
            int end_time = start_cook + times[1];
            prev = end_time;
            waiting += end_time - arrive;
        }

        return waiting / n;
    }
};
