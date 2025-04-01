impl Solution {
    pub fn most_points(questions: Vec<Vec<i32>>) -> i64 {
        let n = questions.len();
        let mut dp = vec![-1; n];
        
        fn solve(questions: &Vec<Vec<i32>>, i: usize, dp: &mut Vec<i64>) -> i64 {
            if i >= questions.len() {
                return 0;
            }

            if dp[i] != -1 {
                return dp[i];
            }

            // Skip the question
            let skip = solve(questions, i + 1, dp);

            // Solve the question
            let take = questions[i][0] as i64 
                + solve(questions, i + 1 + questions[i][1] as usize, dp);

            dp[i] = skip.max(take);
            dp[i]
        }

        solve(&questions, 0, &mut dp)
    }
}

/// https://leetcode.com/problems/solving-questions-with-brainpower/?envType=daily-question&envId=2025-04-01
