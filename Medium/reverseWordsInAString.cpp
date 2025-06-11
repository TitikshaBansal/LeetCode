class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string temp = "";
        
        for(int i = 0; i < s.length(); i++) {
            if(s[i] != ' ') {
                temp += s[i];
            } else {
                if(!temp.empty()) {
                    st.push(temp);
                    temp = "";
                }
            }
        }
        
        if(!temp.empty()) {
            st.push(temp);
        }
        
        string ans = "";
        while(!st.empty()) {
            ans += st.top();
            st.pop();
            if(!st.empty()) ans += " ";
        }
        
        return ans;
    }
};


// https://leetcode.com/problems/reverse-words-in-a-string/
