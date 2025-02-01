class Solution {
public:
    string findValidPair(string s) {
        vector<int> count(10, 0);
        string str = "";
        
        for (char i : s) {
            count[i - '0']++;
        }

        for (int i = 0; i < s.length() - 1; i++) {
            if(s[i] == s[i+1]) continue;
            if (count[s[i] - '0'] == s[i] - '0' && count[s[i+1] - '0'] == s[i+1] - '0') {
                str = str + s[i] + s[i+1];
                return str;  
            }
        }

        return str; 
    }
};

// https://leetcode.com/problems/find-valid-pair-of-adjacent-digits-in-string/
