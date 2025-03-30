impl Solution {
    fn recursion( start: usize, n: usize, pref_sum: &Vec<i64>, suff_costs: &Vec<i64>, k: i64, dp: &mut Vec<Option<i64>>) -> i64 {
        if start == n {
            return 0;
        }

        if let Some(val) = dp[start] {
            return val;
        }

        let mut ans = i64::MAX;

        for end in start..n {
            let sum_till_pos = pref_sum[end];
            let suff_cost = suff_costs[start];
            let subarray_cost = suff_cost - suff_costs.get(end + 1).unwrap_or(&0);
            let cost = sum_till_pos * subarray_cost + k * suff_cost;

            ans = ans.min(cost + Self::recursion(end + 1, n, pref_sum, suff_costs, k, dp));
        }

        dp[start] = Some(ans);
        ans
    }

    pub fn minimum_cost(nums: Vec<i32>, cost: Vec<i32>, k: i32) -> i64 {
        let n = nums.len();
        let mut pref_sum = vec![0; n];
        let mut suff_costs = vec![0; n];

        pref_sum[0] = nums[0] as i64;
        for i in 1..n {
            pref_sum[i] = pref_sum[i - 1] + nums[i] as i64;
        }

        suff_costs[n - 1] = cost[n - 1] as i64;
        for i in (0..n - 1).rev() {
            suff_costs[i] = suff_costs[i + 1] + cost[i] as i64;
        }

        let mut dp = vec![None; n + 1];
        Self::recursion(0, n, &pref_sum, &suff_costs, k as i64, &mut dp)
    }
}

/// https://leetcode.com/problems/minimum-cost-to-divide-array-into-subarrays/
