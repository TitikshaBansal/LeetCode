class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> productCount;
        int n = nums.size();
        
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int product = nums[i] * nums[j];
                productCount[product]++;
            }
        }
        int result = 0;
        for (auto& entry : productCount) {
            int count = entry.second;
            if (count > 1) {
                result += 8 * (count * (count - 1) / 2);
            }
        }
        
        return result;
    }
};

// https://leetcode.com/problems/tuple-with-same-product/?envType=daily-question&envId=2025-02-06
