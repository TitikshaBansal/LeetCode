class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        // Sort nums once outside of the loop
        sort(nums.begin(), nums.end());
        int count = 0;
        int operations = 0;
        // Iterate through nums and count operations needed for each unique number
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[i - 1]) {
                // Increase operations for each new unique number found
                ++operations;
            }
            // Add operations needed so far for each element
            count += operations;
        }
        return count;
    }
};
