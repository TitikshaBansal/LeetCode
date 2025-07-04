class Solution {
public:
    int similarPairs(vector<string>& words) {
        unordered_map<int, int> freq;
        for (const string& word : words) {
            int mask = 0;
            for (char c : word)
                mask |= 1 << (c - 'a');
            freq[mask]++;
        }

        int ans = 0;
        for (auto& [mask, count] : freq) {
            ans += count * (count - 1) / 2;
        }

        return ans;
    }
};

// https://leetcode.com/problems/count-pairs-of-similar-strings/
