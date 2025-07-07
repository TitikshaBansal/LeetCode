class Solution {
public:
    unordered_map<int, int> memo;

    int getPower(int x) {
        if (x == 1) return 0;
        if (memo.count(x)) return memo[x];
        if (x % 2 == 0)
            memo[x] = 1 + getPower(x / 2);
        else
            memo[x] = 1 + getPower(3 * x + 1);
        return memo[x];
    }

    int getKth(int lo, int hi, int k) {
        vector<pair<int, int>> nums;
        for (int i = lo; i <= hi; ++i) {
            nums.push_back({getPower(i), i});
        }
        sort(nums.begin(), nums.end());
        return nums[k - 1].second;
    }
};


// https://leetcode.com/problems/sort-integers-by-the-power-value/
