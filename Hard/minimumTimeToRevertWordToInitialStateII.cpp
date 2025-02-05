typedef unsigned long long ull;
 
struct Hash {
    vector<ull> prefix, power;
    ull base;
    
    Hash(const string &s, ull base = 131ULL) : base(base) {
        int n = s.size();
        prefix.resize(n+1, 0);
        power.resize(n+1, 0);
        power[0] = 1;
        for (int i = 0; i < n; i++){
            prefix[i+1] = prefix[i] * base + (ull)(s[i]);
            power[i+1] = power[i] * base;
        }
    }
    
    ull get(int l, int r) {
        return prefix[r+1] - prefix[l] * power[r-l+1];
    }
};
 
class Solution {
public:
    int minimumTimeToInitialState(string word, int k) {
        int n = word.size();
        Hash h(word);
        int maxT = (n + k - 1) / k;
        
        for (int t = 1; t <= maxT; t++){
            long long prod = (long long)t * k;
            if (prod >= n) return t;
            int forcedLen = n - prod; 
            if (h.get(prod, n - 1) == h.get(0, forcedLen - 1)) return t;
        }
        return maxT;
    }
};

// https://leetcode.com/problems/minimum-time-to-revert-word-to-initial-state-ii/
