class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;

        vector<int> s1_freq(26,0), window_freq(26,0);

        for(char c : s1) s1_freq[c - 'a']++;

        for(int i =0; i<s1.size(); i++){
            window_freq[s2[i] - 'a']++;
        }

        for(int i= s1.size(); i< s2.size(); ++i){
            if(s1_freq == window_freq) return true;

            window_freq[s2[i]-'a']++;
            window_freq[s2[i - s1.size()] - 'a']--;
        }

        return s1_freq == window_freq;
    }
};






// https://leetcode.com/problems/permutation-in-string/
