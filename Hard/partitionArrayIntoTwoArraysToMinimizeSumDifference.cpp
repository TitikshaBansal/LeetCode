class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size() / 2;
        vector<int> left(nums.begin(), nums.begin() + n);
        vector<int> right(nums.begin() + n, nums.end());

        auto getSubsetSums = [&](vector<int>& arr) {
            int m = arr.size();
            unordered_map<int, vector<int>> subsets;
            for (int mask = 0; mask < (1 << m); mask++) {
                int sum = 0;
                int count = 0;
                for (int i = 0; i < m; i++) {
                    if (mask & (1 << i)) {
                        sum += arr[i];
                        count++;
                    }
                }
                subsets[count].push_back(sum);
            }
            return subsets;
        };

        auto leftSums = getSubsetSums(left);
        auto rightSums = getSubsetSums(right);

        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int ans = abs(totalSum - 2 * accumulate(left.begin(), left.end(), 0)); // initial worst case

        for (auto& [lcnt, lvec] : leftSums) {
            int rcnt = n - lcnt;
            if (!rightSums.count(rcnt)) continue;

            auto& rvec = rightSums[rcnt];
            sort(rvec.begin(), rvec.end());

            for (int lsum : lvec) {
                int target = totalSum / 2 - lsum;
                auto it = lower_bound(rvec.begin(), rvec.end(), target);

                if (it != rvec.end()) {
                    int sum1 = lsum + *it;
                    int sum2 = totalSum - sum1;
                    ans = min(ans, abs(sum1 - sum2));
                }

                if (it != rvec.begin()) {
                    --it;
                    int sum1 = lsum + *it;
                    int sum2 = totalSum - sum1;
                    ans = min(ans, abs(sum1 - sum2));
                }
            }
        }

        return ans;
    }
};

// https://leetcode.com/problems/partition-array-into-two-arrays-to-minimize-sum-difference/
