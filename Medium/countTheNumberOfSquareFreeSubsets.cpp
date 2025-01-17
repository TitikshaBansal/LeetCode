class Solution {
public:
    int squareFreeSubsets(vector<int>& nums) {
        const int MOD = 1e9 + 7;
        const vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
        const int primeCount = primes.size();
        unordered_map<int, int> numMask;
        
        for (int i = 1; i <= 30; ++i) {
            int mask = 0, x = i;
            bool isSquareFree = true;
            for (int j = 0; j < primeCount; ++j) {
                int prime = primes[j];
                int count = 0;
                while (x % prime == 0) {
                    x /= prime;
                    count++;
                }
                if (count > 1) {
                    isSquareFree = false;
                    break;
                }
                if (count == 1) mask |= (1 << j);
            }
            if (isSquareFree) numMask[i] = mask;
        }
        
        vector<int> dp(1 << primeCount, 0);
        dp[0] = 1; 

        unordered_map<int, int> freq;
        for (int num : nums) freq[num]++;

        int countOnes = freq[1];
        freq.erase(1); 
        for (auto& [num, count] : freq) {
            if (numMask.find(num) == numMask.end()) continue; 
            int mask = numMask[num];
            vector<int> newDP = dp; 
            for (int state = 0; state < (1 << primeCount); ++state) {
                if ((state & mask) == 0) { 
                    newDP[state | mask] = (newDP[state | mask] + (long long)dp[state] * count % MOD) % MOD;
                }
            }
            dp = newDP; 
        }
        int result = 0;
        for (int state = 1; state < (1 << primeCount); ++state) {
            result = (result + dp[state]) % MOD;
        }
        if (countOnes > 0) {
            long long pow2 = 1;
            for (int i = 0; i < countOnes; ++i) {
                pow2 = (pow2 * 2) % MOD;
            }
            result = (result * pow2 % MOD + pow2 - 1 + MOD) % MOD;
        }
        
        return result;
    }
};

// https://leetcode.com/problems/count-the-number-of-square-free-subsets/
