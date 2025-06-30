class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int total = accumulate(cardPoints.begin(), cardPoints.end(), 0);

        if (k == n) return total;  // all cards picked

        int windowSize = n - k;
        int windowSum = 0;
        for (int i = 0; i < windowSize; i++) {
            windowSum += cardPoints[i];
        }

        int minWindowSum = windowSum;

        for (int i = windowSize; i < n; i++) {
            windowSum += cardPoints[i] - cardPoints[i - windowSize];
            minWindowSum = min(minWindowSum, windowSum);
        }

        return total - minWindowSum;
    }
};


// https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/
