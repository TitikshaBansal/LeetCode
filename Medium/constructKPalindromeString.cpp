class Solution {
public:
    bool canConstruct(string s, int k) {
        if(k>s.length()) return false;
        vector<int> arr(26,0);
        for(char i : s){
            arr[i-'a']++;
        }
        int count =0;
        for(int i=0; i<26; i++){
            if(arr[i]%2 == 1) count++;
        }
        return count>k ? false:true;
    }
};

// https://leetcode.com/problems/construct-k-palindrome-strings/?envType=daily-question&envId=2025-01-11
