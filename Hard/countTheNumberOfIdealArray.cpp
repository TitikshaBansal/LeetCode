const int MOD = 1e9 + 7; 
const int MAX_N = 1e4 + 10; 
const int MAX_P = 15;
int combination[MAX_N + MAX_P][MAX_P + 1]; 
vector<int> primeFactors[MAX_N]; 
int sieve[MAX_N]; 

class Solution {
public:
    Solution() {
        if (combination[0][0]) {
            return;  
        }
        for (int i = 2; i < MAX_N; i++) {
            if (sieve[i] == 0) {  
                for (int j = i; j < MAX_N; j += i) {
                    sieve[j] = i;  
                }
            }
        }
        for (int i = 2; i < MAX_N; i++) {
            int x = i;
            while (x > 1) {
                int prime = sieve[x];
                int count = 0;
                while (x % prime == 0) {
                    x /= prime;
                    count++;
                }
                primeFactors[i].push_back(count); 
            }
        }
        combination[0][0] = 1;
        for (int i = 1; i < MAX_N + MAX_P; i++) {
            combination[i][0] = 1;  // nC0 is always 1
            for (int j = 1; j <= min(i, MAX_P); j++) {
                combination[i][j] = (combination[i - 1][j] + combination[i - 1][j - 1]) % MOD;
            }
        }
    }

    int idealArrays(int n, int maxValue) {
        long long result = 0;

        for (int x = 1; x <= maxValue; x++) {
            long long product = 1;
            for (int primePower : primeFactors[x]) {
                product = product * combination[n + primePower - 1][primePower] % MOD;
            }
            result = (result + product) % MOD;
        }

        return result; 
    }
};

// https://leetcode.com/problems/count-the-number-of-ideal-arrays/?envType=daily-question&envId=2025-04-22
