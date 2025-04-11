class Solution {
public:
    void solve(vector<string>& result, int open, int close, string current){
        if (open == 0 && close == 0) {
            result.push_back(current);
            return;
        }

        if (open > 0) {
            solve( result, open - 1, close, current + '(');
        }

        if (close > open) {
            solve(result, open, close - 1, current + ')');
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(ans, n , n, "");
        return ans;
    }
};

// https://leetcode.com/problems/generate-parentheses/
