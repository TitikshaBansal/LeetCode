impl Solution {
    pub fn put_marbles(weights: Vec<i32>, k: i32) -> i64 {
        let n = weights.len();
        let mut pair: Vec<i32> = Vec::with_capacity(n - 1);
        
        for i in 0..n-1 {
            pair.push(weights[i] + weights[i + 1]);
        }
        
        pair.sort();
        
        let mut ans: i64 = 0;
        for i in 0..(k as usize - 1) {
            ans += (pair[n - 2 - i] - pair[i]) as i64;
        }
        
        ans
    }
}

/// https://leetcode.com/problems/put-marbles-in-bags/?envType=daily-question&envId=2025-03-31
