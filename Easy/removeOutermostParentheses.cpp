class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        stack<char> st;
        int start = 0;
        for(int end =0; end < s.length(); end++){
            if(s[end] == '(') st.push(s[end]);
            else st.pop();
            if(st.size() == 0){
                int len = end - start -1;
                ans += s.substr(start + 1, len);
                start = end + 1;
            }
        }
        return ans;
    }
};

// https://leetcode.com/problems/remove-outermost-parentheses/
