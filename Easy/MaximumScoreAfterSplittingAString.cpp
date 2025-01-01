class Solution {
public:
    int maxScore(string s) {
        int ans= INT_MIN;
        int zero=0;
        int one=0;
        for(char i : s) one += (i-'0');
        for(int i=0; i<s.length()-1; i++){
            if(s[i] == '0') zero++;
            else one--;
            ans= max(ans, zero+one);
        }
        return ans;
    }
};


// https://leetcode.com/problems/maximum-score-after-splitting-a-string/?envType=daily-question&envId=2025-01-01
