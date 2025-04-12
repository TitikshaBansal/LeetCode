#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> fact;

    Solution() {
        // Precompute factorials up to 10!
        fact.resize(11, 1);
        for (int i = 1; i <= 10; i++) {
            fact[i] = fact[i - 1] * i;
        }
    }

    bool isDivisible(const string& s, int k) {
        return stoll(s) % k == 0; // stoll to handle large numbers
    }

    void generatePalindromes(int n, int k, unordered_set<string>& palDigitSets) {
        int half = (n + 1) / 2;
        int start = (n == 1) ? 1 : pow(10, half - 1);
        int end = pow(10, half);

        for (int i = start; i < end; i++) {
            string left = to_string(i);
            string right = left;
            if (n % 2 == 1) right.pop_back();
            reverse(right.begin(), right.end());
            string fullPal = left + right;
            if (isDivisible(fullPal, k)) {
                string sortedDigits = fullPal;
                sort(sortedDigits.begin(), sortedDigits.end());
                palDigitSets.insert(sortedDigits);
            }
        }
    }

    long long countPermutations(const string& digits) {
        unordered_map<char, int> freq;
        for (char c : digits) freq[c]++;

        int n = digits.size();
        long long total = fact[n];  // total permutations

        for (auto& [_, cnt] : freq) {
            total /= fact[cnt];     // divide by frequency of each digit
        }

        // Subtract permutations starting with 0
        if (freq.count('0')) {
            freq['0']--;
            int reducedLen = n - 1;
            long long invalid = fact[reducedLen];
            for (auto& [_, cnt] : freq) {
                invalid /= fact[cnt];
            }
            total -= invalid;
            freq['0']++; // restore
        }

        return total;
    }

    long long countGoodIntegers(int n, int k) {
        unordered_set<string> palDigitSets;
        generatePalindromes(n, k, palDigitSets);

        long long res = 0;
        for (const auto& digitKey : palDigitSets) {
            res += countPermutations(digitKey);
        }
        return res;
    }
};

// https://leetcode.com/problems/find-the-count-of-good-integers/?envType=daily-question&envId=2025-04-12
