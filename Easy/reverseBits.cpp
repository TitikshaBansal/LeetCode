class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        bitset<32> num(n);  
        string s = num.to_string();
        reverse(s.begin(), s.end()); 
        return bitset<32>(s).to_ulong();
    }
};

// https://leetcode.com/problems/reverse-bits/
