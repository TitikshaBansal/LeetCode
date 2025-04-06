impl Solution {
    pub fn min_add_to_make_valid(s: String) -> i32 {
        let mut stack = Vec::new();
        
        for c in s.chars() {
            if c == '(' {
                stack.push(c);
            } else if c == ')' {
                if let Some('(') = stack.last() {
                    stack.pop();
                } else {
                    stack.push(c);
                }
            }
        }

        stack.len() as i32
    }
}

// https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/
