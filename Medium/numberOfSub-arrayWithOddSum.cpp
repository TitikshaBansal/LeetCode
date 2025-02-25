class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int count = 0, prefixSum = 0;
        int oddCount = 0, evenCount = 1;

        for (int num : arr) {
            prefixSum += num;
            if (prefixSum % 2 == 0) {
                count += oddCount;
                evenCount++;
            } else {
                count += evenCount;
                oddCount++;
            }
            count %= MOD; 
        }
        return count;
    }
};

// https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/?envType=daily-question&envId=2025-02-25
