const int MOD = 1e9 + 7;
const int MAX = 1e5 + 5;

long long fact[MAX];
long long invFact[MAX];
bool initialized = false;

// Fast exponentiation
long long qpow(long long x, int n) {
    long long res = 1;
    while (n) {
        if (n & 1) res = res * x % MOD;
        x = x * x % MOD;
        n >>= 1;
    }
    return res;
}

// Precompute factorials and inverse factorials
void init() {
    if (initialized) return;
    initialized = true;

    fact[0] = 1;
    for (int i = 1; i < MAX; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }

    invFact[MAX - 1] = qpow(fact[MAX - 1], MOD - 2);
    for (int i = MAX - 2; i >= 0; i--) {
        invFact[i] = invFact[i + 1] * (i + 1) % MOD;
    }
}

// Compute nCk % MOD
long long comb(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fact[n] * invFact[k] % MOD * invFact[n - k] % MOD;
}

class Solution {
public:
    int countGoodArrays(int n, int m, int k) {
        init();
        return comb(n - 1, k) * m % MOD * qpow(m - 1, n - k - 1) % MOD;
    }
};

// https://leetcode.com/problems/count-the-number-of-arrays-with-k-matching-adjacent-elements/?envType=daily-question&envId=2025-06-17
