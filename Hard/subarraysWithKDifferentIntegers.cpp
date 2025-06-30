class Solution {
public:
    int atMostK(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int, int> freq;
        int left = 0;

        for (int right = 0; right < nums.size(); right++) {
            if (freq[nums[right]] == 0) k--;
            freq[nums[right]]++;

            while (k < 0) {
                freq[nums[left]]--;
                if (freq[nums[left]] == 0) k++;
                left++;
            }

            ans += right - left + 1;
        }

        return ans;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }
};

// https://leetcode.com/problems/subarrays-with-k-different-integers/
