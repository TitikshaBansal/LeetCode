impl Solution {
    pub fn four_sum(mut nums: Vec<i32>, target: i32) -> Vec<Vec<i32>> {
        let mut ans = Vec::new();
        let n = nums.len();

        if n < 4 {
            return ans;
        }
        
        nums.sort();

        for i in 0..n - 3 {
            if i > 0 && nums[i] == nums[i - 1] {
                continue;
            }
            for j in i + 1..n - 2 {
                if j > i + 1 && nums[j] == nums[j - 1] {
                    continue;
                }
                let mut k = j + 1;
                let mut l = n - 1;

                while k < l {
                    let sum = nums[i] as i64 + nums[j] as i64 + nums[k] as i64 + nums[l] as i64;
                    if sum == target as i64 {
                        ans.push(vec![nums[i], nums[j], nums[k], nums[l]]);
                        k += 1;
                        l -= 1;
                        while k < l && nums[k] == nums[k - 1] {
                            k += 1;
                        }
                        while k < l && nums[l] == nums[l + 1] {
                            l -= 1;
                        }
                    } else if sum < target as i64 {
                        k += 1;
                    } else {
                        l -= 1;
                    }
                }
            }
        }

        ans
    }
}

// https://leetcode.com/problems/4sum/
