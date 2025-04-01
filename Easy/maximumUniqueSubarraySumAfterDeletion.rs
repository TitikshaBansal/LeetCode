impl Solution {
    pub fn max_sum(nums: Vec<i32>) -> i32 {
        let mut seen = vec![false; 201]; 
        let mut max_neg = -101;
        let mut sum = 0;

        for &num in &nums {
            if num > 0 && !seen[(num + 100) as usize] {
                sum += num;
                seen[(num + 100) as usize] = true;
            }
            max_neg = max_neg.max(num);
        }

        if sum > 0 { sum } else { max_neg }
    }
}

/// https://leetcode.com/problems/maximum-unique-subarray-sum-after-deletion/
