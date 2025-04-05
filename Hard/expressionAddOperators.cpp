class Solution {
public:
    vector<string> result;

    void dfs(string& num, int target, int pos, long currVal, long prevOperand, string expr) {
        if (pos == num.size()) {
            if (currVal == target) result.push_back(expr);
            return;
        }

        for (int i = pos; i < num.size(); ++i) {
            if (i != pos && num[pos] == '0') break;

            string part = num.substr(pos, i - pos + 1);
            long currNum = stol(part);

            if (pos == 0) {
                // First number, no operator before it
                dfs(num, target, i + 1, currNum, currNum, part);
            } else {
                // Addition
                dfs(num, target, i + 1, currVal + currNum, currNum, expr + "+" + part);
                // Subtraction
                dfs(num, target, i + 1, currVal - currNum, -currNum, expr + "-" + part);
                // Multiplication (backtrack the previous operation and apply multiplication)
                dfs(num, target, i + 1, currVal - prevOperand + (prevOperand * currNum), prevOperand * currNum, expr + "*" + part);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        result.clear();
        if (num.empty()) return result;
        dfs(num, target, 0, 0, 0, "");
        return result;
    }
};

// https://leetcode.com/problems/expression-add-operators/
