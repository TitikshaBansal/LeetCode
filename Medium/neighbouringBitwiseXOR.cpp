class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int x = derived[0];
        for(int i=1; i<derived.size(); i++){
            x^=derived[i];
        }
        return x == 0? true : false;
    }
};

// https://leetcode.com/problems/neighboring-bitwise-xor/?envType=daily-question&envId=2025-01-17
