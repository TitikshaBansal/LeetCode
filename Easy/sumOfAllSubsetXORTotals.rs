impl Solution {
    pub fn subset_xor_sum(nums: Vec<i32>) -> i32 {
        let mut result = 0;
        for num in &nums{
            result |= num;
        }
        result << (nums.len() - 1)
    }
}

// https://leetcode.com/problems/sum-of-all-subset-xor-totals/?envType=daily-question&envId=2025-04-05
