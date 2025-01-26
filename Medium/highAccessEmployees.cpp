class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        map<string, vector<int>> m;
        for (auto& entry : access_times) {
            string name = entry[0];
            string time = entry[1];
            m[name].push_back(stoi(time));
        }

        vector<string> ans;

        for (auto& [name, times] : m) {
            sort(times.begin(), times.end());
            int n = times.size();
            bool flag = false;
            for(int i=0; i+3<=n; i++) flag |= times[i+2]<times[i] +100;
            if(flag) ans.push_back(name);
        }

        return ans;
    }
};

// https://leetcode.com/problems/high-access-employees/
