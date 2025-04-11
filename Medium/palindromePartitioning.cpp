class Solution {
public:
    bool isValid(string st){
        int s =0, e = st.length()-1;
        while(s<=e){
            if(st[s] != st[e]) return false;
            s++;
            e--;
        }
        return true;
    }

    void solve(vector<vector<string>>& ans, vector<string>& part, string& s, int index) {
        if (index == s.length()) {
            ans.push_back(part);
            return;
        }

        for (int i = index; i < s.length(); ++i) {
            string temp = s.substr(index, i - index + 1);
            if (isValid(temp)) {
                part.push_back(temp);
                solve(ans, part, s, i + 1);
                part.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> part;
        solve(ans, part, s, 0);
        return ans;
    }
};

// https://leetcode.com/problems/palindrome-partitioning/
