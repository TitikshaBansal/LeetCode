class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int, int> count;
        
        for (int num : nums) {
            count[num]++;
        }
        
        for (const auto& pair : count) {
            if (pair.second % 2 != 0) {
                return false; 
            }
        }
        
        return true; 
    }
};

// https://leetcode.com/problems/divide-array-into-equal-pairs/?envType=daily-question&envId=2025-03-17
