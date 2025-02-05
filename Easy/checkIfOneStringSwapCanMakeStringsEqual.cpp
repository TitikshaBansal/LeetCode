class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n = s1.length();
        int count =0;
        vector<int> count1(26,0);
        vector<int> count2(26,0);
        for(int i=0; i<n; i++){
            if(s1[i] != s2[i]) {
                count++;
                count1[s1[i]-'a']++;
                count2[s2[i]-'a']++;
            }
            if(count>2) return false;
        }
        return count1 == count2;
    }
};

// https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/?envType=daily-question&envId=2025-02-05
