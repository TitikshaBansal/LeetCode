class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> stk;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') stk.push(i);
            else if (s[i] == ')') {
                int j = stk.top();
                stk.pop();
                std::reverse(s.begin() + j + 1, s.begin() + i);
            }
        }
        string result;
        for (char c : s) {
            if (c != '(' && c != ')') {
                result += c;
            }
        }

        return result;
    }
};
