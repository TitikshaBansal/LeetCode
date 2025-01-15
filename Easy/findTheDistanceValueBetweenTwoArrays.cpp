class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int ans = 0;
        sort(arr2.begin(), arr2.end());
        for (int num1 : arr1) {
            auto lower = lower_bound(arr2.begin(), arr2.end(), num1 - d);
            auto upper = upper_bound(arr2.begin(), arr2.end(), num1 + d);
            if (lower == upper) ans++;
        }
        return ans;
    }
};

// https://leetcode.com/problems/find-the-distance-value-between-two-arrays/
