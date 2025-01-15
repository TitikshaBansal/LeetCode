class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int setBitsInNum2 = __builtin_popcount(num2); 
        bitset<32> result; 
        bitset<32> num1Bits(num1); 
        for (int i = 31; i >= 0 && setBitsInNum2 > 0; --i) {
            if (num1Bits[i]) {
                result[i] = 1;
                setBitsInNum2--;
            }
        }
        for (int i = 0; i < 32 && setBitsInNum2 > 0; ++i) {
            if (!result[i]) {
                result[i] = 1;
                setBitsInNum2--;
            }
        }
        return (int)result.to_ulong();
    }
};

// https://leetcode.com/problems/minimize-xor/?envType=daily-question&envId=2025-01-15
