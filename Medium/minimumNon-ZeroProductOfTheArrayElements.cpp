class Solution {
public:
    const long long MOD = 1e9 + 7;

    // Function to calculate (base^exp) % MOD using modular exponentiation
    long long modExp(long long base, long long exp, long long mod) {
        long long result = 1;
        base = base % mod; // Ensure base is within mod range initially
        while (exp > 0) {
            if (exp % 2 == 1) { // If exp is odd
                result = (result * base) % mod;
            }
            base = (base * base) % mod; // Reduce base after squaring
            exp /= 2;
        }
        return result;
    }

    int minNonZeroProduct(int p) {
        // Calculate 2^p - 1 (maxNum) and 2^p - 2 (secondMax)
        long long maxNum = (1LL << p) - 1; // Largest number in the range
        long long secondMax = maxNum - 1; // Second largest number
        long long count = (1LL << (p - 1)) - 1; // Number of times to use secondMax

        // Compute the result
        long long product = maxNum % MOD;
        product = (product * modExp(secondMax, count, MOD)) % MOD;

        return product;
    }
};

// https://leetcode.com/problems/minimum-non-zero-product-of-the-array-elements/
