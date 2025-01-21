class Solution {
public:
    long long sumScores(string s) {
        int n = s.length();
        vector<int> Z(n, 0);

        int left = 0, right = 0;
        for (int i = 1; i < n; i++) {
            if (i <= right) {
                Z[i] = min(right - i + 1, Z[i - left]);
            }
            while (i + Z[i] < n && s[Z[i]] == s[i + Z[i]]) {
                Z[i]++;
            }
            if (i + Z[i] - 1 > right) {
                left = i;
                right = i + Z[i] - 1;
            }
        }
        long long totalScore = n;
        totalScore += accumulate(Z.begin(), Z.end(), 0LL);
        return totalScore;
    }
};

// https://leetcode.com/problems/sum-of-scores-of-built-strings/
