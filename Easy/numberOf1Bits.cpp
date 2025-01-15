class Solution {
public:
    int hammingWeight(int n) {
        bitset<32> num(n);
        return num.count();
    }
};

// https://leetcode.com/problems/number-of-1-bits/
