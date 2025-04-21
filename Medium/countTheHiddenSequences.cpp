class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long minPrefix = 0, maxPrefix = 0;
        long long prefixSum = 0;

        for (int diff : differences) {
            prefixSum += diff;
            minPrefix = min(minPrefix, prefixSum);
            maxPrefix = max(maxPrefix, prefixSum);
        }

        long long minStart = lower - minPrefix;
        long long maxStart = upper - maxPrefix;

        return max(0LL, maxStart - minStart + 1);
    }
};


// https://leetcode.com/problems/count-the-hidden-sequences/?envType=daily-question&envId=2025-04-21
