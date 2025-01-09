class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count =0;
        int n = pref.length();
        for(string word : words){
            if(word.substr(0, n) == pref) count++;
        }
        return count;
    }
};

// https://leetcode.com/problems/counting-words-with-a-given-prefix/?envType=daily-question&envId=2025-01-09
