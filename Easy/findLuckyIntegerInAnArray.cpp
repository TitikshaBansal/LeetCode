class Solution {
public:
    int findLucky(vector<int>& arr) {
        map<int, int> m;
        for(int num : arr) m[num]++;
        int ans = -1;
        for(auto [num, count] : m) if (num == count) ans = num;
        return ans;
    }
};


// https://leetcode.com/problems/find-lucky-integer-in-an-array/?envType=daily-question&envId=2025-07-05
