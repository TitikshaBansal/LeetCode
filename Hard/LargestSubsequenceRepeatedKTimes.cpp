class Solution {
public:
    string s;
    int k;

    // Check if seq * k is a subsequence of s
    bool isKSubsequence(const string& seq) {
        int i = 0, count = 0;
        for (char c : s) {
            if (c == seq[i]) {
                i++;
                if (i == seq.size()) {
                    i = 0;
                    count++;
                    if (count == k) return true;
                }
            }
        }
        return false;
    }

    string longestSubsequenceRepeatedK(string _s, int _k) {
        s = _s;
        k = _k;
        
        // Step 1: Count frequencies
        unordered_map<char, int> freq;
        for (char c : s) freq[c]++;
        
        // Step 2: Build candidate character pool (only those with enough frequency)
        string chars;
        for (char c = 'z'; c >= 'a'; --c) {
            if (freq[c] >= k) chars += c;
        }

        // Step 3: BFS
        queue<string> q;
        q.push("");
        string best = "";

        while (!q.empty()) {
            string curr = q.front(); q.pop();
            for (char c : chars) {
                string next = curr + c;
                if (isKSubsequence(next)) {
                    if (next.size() > best.size() || (next.size() == best.size() && next > best)) {
                        best = next;
                    }
                    if (next.size() < 7) {  // Reasonable limit due to exponential growth
                        q.push(next);
                    }
                }
            }
        }

        return best;
    }
};

// https://leetcode.com/problems/longest-subsequence-repeated-k-times/?envType=daily-question&envId=2025-06-27
