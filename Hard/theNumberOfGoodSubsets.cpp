class Solution {
public:
    int numberOfGoodSubsets(vector<int>& nums) {
        constexpr int MOD = 1'000'000'007;
        vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
        int primeCount = primes.size();

        // Precompute prime bitmasks for numbers 1 to 30
        vector<int> numToMask(31, 0);
        for (int i = 2; i <= 30; ++i) {
            int mask = 0, num = i;
            bool isValid = true;
            for (int j = 0; j < primeCount; ++j) {
                int prime = primes[j], count = 0;
                while (num % prime == 0) {
                    num /= prime;
                    ++count;
                }
                if (count > 1) {
                    isValid = false;  // Number has repeated prime factors
                    break;
                }
                if (count == 1) {
                    mask |= (1 << j);  // Set the bit for this prime
                }
            }
            if (isValid) {
                numToMask[i] = mask;
            }
        }

        // Count the frequency of each number in nums
        vector<int> freq(31, 0);
        for (int num : nums) {
            ++freq[num];
        }

        // DP array to count subsets with distinct prime products
        vector<int> dp(1 << primeCount, 0);
        dp[0] = 1;  // Base case: empty subset

        // Process numbers from 2 to 30
        for (int num = 2; num <= 30; ++num) {
            int mask = numToMask[num];
            if (mask == 0 || freq[num] == 0) continue;

            // Update DP in reverse to avoid overwriting
            for (int oldMask = (1 << primeCount) - 1; oldMask >= 0; --oldMask) {
                if ((oldMask & mask) == 0) {  // No overlap in primes
                    dp[oldMask | mask] = (dp[oldMask | mask] + (long long)dp[oldMask] * freq[num]) % MOD;
                }
            }
        }

        // Sum up all valid subsets
        int result = 0;
        for (int mask = 1; mask < (1 << primeCount); ++mask) {
            result = (result + dp[mask]) % MOD;
        }

        // Account for the number of 1s in the input
        int onesCount = freq[1];
        if (onesCount > 0) {
            result = (long long)result * modPow(2, onesCount, MOD) % MOD;
        }

        return result;
    }

private:
    int modPow(int base, int exp, int mod) {
        int result = 1;
        while (exp > 0) {
            if (exp % 2 == 1) {
                result = (long long)result * base % mod;
            }
            base = (long long)base * base % mod;
            exp /= 2;
        }
        return result;
    }
};

// https://leetcode.com/problems/the-number-of-good-subsets/
