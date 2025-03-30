class Solution {
public:
    int reverseDegree(string s) {
        int ans = 0;
        for(int i=0; i<s.length(); i++){
            int rev = 26 - ((s[i] - 'a')%26);
            ans += rev*(i+1);
        }
        return ans;
    }
};

// https://leetcode.com/contest/biweekly-contest-153/problems/reverse-degree-of-a-string/
