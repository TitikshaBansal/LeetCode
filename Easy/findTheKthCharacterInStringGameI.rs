impl Solution {
    pub fn kth_character(k: i32) -> char {
        let mut k = k;
        let mut ans = 0;

        while k != 1 {
            let mut t = 31 - k.leading_zeros();
            if 1 << t == k {
                t -= 1;
            }
            k -= 1 << t;
            ans += 1;
        }
        (b'a' + ans) as char
    }
}


// https://leetcode.com/problems/find-the-k-th-character-in-string-game-i/?envType=daily-question&envId=2025-07-03
