impl Solution {
    pub fn min_costs(cost: Vec<i32>) -> Vec<i32> {
        let mut ans = Vec::new();
        let mut mini = i32::MAX;
        
        for &c in &cost {
            mini = mini.min(c);
            ans.push(mini);
        }
        
        ans
    }
}

///https://leetcode.com/problems/minimum-cost-to-reach-every-position/
