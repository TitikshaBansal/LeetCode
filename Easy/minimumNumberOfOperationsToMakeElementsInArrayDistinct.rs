impl Solution {
    pub fn minimum_operations(nums: Vec<i32>) -> i32 {
        let mut v = vec![0; 101];
        let mut i = nums.len();

        while i > 0 {
            i -= 1;
            if v[nums[i] as usize] > 0 {
                return (i / 3 + 1) as i32;
            }
            v[nums[i] as usize] += 1;
        }

        0
    }
}

// https://leetcode.com/problems/minimum-number-of-operations-to-make-elements-in-array-distinct/?envType=daily-question&envId=2025-04-08
