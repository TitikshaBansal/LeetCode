class Solution {
public:
    int minimumLength(string s) {
        int n = s.length();
        if(n<3) return n;
        vector<int> v(26,0);
        for(char i : s) v[i-'a']++;
        int ans =0;
        for(int i=0; i<26; i++){
            while(v[i]>2) v[i]-=2;
            ans +=v[i];
        }
        return ans;
    }
};

// https://leetcode.com/problems/minimum-length-of-string-after-operations/?envType=daily-question&envId=2025-01-13
