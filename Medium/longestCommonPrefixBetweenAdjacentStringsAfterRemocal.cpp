class Solution {
public:
    int computeLCP(const string &a, const string &b) {
        int i = 0;
        while (i < a.size() && i < b.size() && a[i] == b[i]) i++;
        return i;
    }

    vector<int> longestCommonPrefix(vector<string>& words) {
        int n = words.size();
        if (n <= 2) return vector<int>(n, 0);

        vector<int> lcp(n - 1);
        for (int i = 0; i < n - 1; ++i) {
            lcp[i] = computeLCP(words[i], words[i + 1]);
        }

        vector<int> prefixMax(n - 1), suffixMax(n - 1);
        prefixMax[0] = lcp[0];
        for (int i = 1; i < n - 1; ++i) {
            prefixMax[i] = max(prefixMax[i - 1], lcp[i]);
        }
        suffixMax[n - 2] = lcp[n - 2];
        for (int i = n - 3; i >= 0; --i) {
            suffixMax[i] = max(suffixMax[i + 1], lcp[i]);
        }

        vector<int> result(n);
        for (int i = 0; i < n; ++i) {
            if (i == 0) {
                result[i] = suffixMax[1];
            } else if (i == n - 1) {
                result[i] = prefixMax[n - 3];
            } else {
                int newLCP = computeLCP(words[i - 1], words[i + 1]);
                int maxLeft = (i >= 2) ? prefixMax[i - 2] : 0;
                int maxRight = (i + 1 < n - 1) ? suffixMax[i + 1] : 0;
                result[i] = max({newLCP, maxLeft, maxRight});
            }
        }
        return result;
    }
};


// https://leetcode.com/problems/longest-common-prefix-between-adjacent-strings-after-removals/
