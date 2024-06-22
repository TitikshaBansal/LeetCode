class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int start = 0, end = 0;
        int sum = 0;
        int count = 0;

        while (end < nums.size()) {
            sum += nums[end]; // Add the current element to the sum

            // If sum exceeds goal, move the start pointer to reduce sum
            while (start <= end && sum > goal) {
                sum -= nums[start];
                start++;
            }

            // If sum equals goal, count all valid subarrays ending at 'end'
            if (sum == goal) {
                int tempStart = start;
                while (tempStart <= end && sum == goal) {
                    count++;
                    if (tempStart < end) {
                        sum -= nums[tempStart];
                    }
                    tempStart++;
                }
                // Restore the sum after counting
                sum = goal;
            }
            
            end++; // Move to the next element
        }
        
        return count;
    }
};
