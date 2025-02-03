class Solution {
public:
    int longestMonotonicSubarray(vector<int>& arr) {
        if (arr.empty()) return 0;

        int inc_len = 1, dec_len = 1, max_len = 1;

        for (size_t i = 1; i < arr.size(); i++) {
            if (arr[i] > arr[i - 1]) {  
                inc_len++; 
                dec_len = 1; 
            } else if (arr[i] < arr[i - 1]) { 
                dec_len++; 
                inc_len = 1;
            } else {  
                inc_len = dec_len = 1;
            }
            max_len = max(max_len, max(inc_len, dec_len));
        }

        return max_len;
    }
};

// https://leetcode.com/problems/longest-strictly-increasing-or-strictly-decreasing-subarray/?envType=daily-question&envId=2025-02-03
