class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> arr;
        for(int i=0; i<=n; i++){
            bitset<32> num(i);
            arr.push_back((int)num.count());
        }
        return arr;
    }
};

// https://leetcode.com/problems/counting-bits/
