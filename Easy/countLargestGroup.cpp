class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int, int> digitSumFreq;
        int maxSize = 0;

        for (int i = 1; i <= n; ++i) {
            int sum = 0, num = i;
            while (num > 0) {
                sum += num % 10;
                num /= 10;
            }
            digitSumFreq[sum]++;
            maxSize = max(maxSize, digitSumFreq[sum]);
        }

        int count = 0;
        for (auto& pair : digitSumFreq) {
            if (pair.second == maxSize)
                count++;
        }

        return count;
    }
};

// https://leetcode.com/problems/count-largest-group/?envType=daily-question&envId=2025-04-23
