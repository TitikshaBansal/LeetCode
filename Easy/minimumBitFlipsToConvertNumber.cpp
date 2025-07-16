class Solution {
public:
    int minBitFlips(int start, int goal) {
        bitset<32> num(start^goal);
        return (int)num.count();
    }
};


// https://leetcode.com/problems/minimum-bit-flips-to-convert-number/
