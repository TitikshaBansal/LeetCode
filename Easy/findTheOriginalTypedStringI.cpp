class Solution {
public:
    int possibleStringCount(string word) {
        int ans = 1;
        char curr = ' ';
        for(char c : word){
            if(c == curr) ans++;
            else curr = c;
        }
        return ans;
    }
};

// https://leetcode.com/problems/find-the-original-typed-string-i/?envType=daily-question&envId=2025-07-01
