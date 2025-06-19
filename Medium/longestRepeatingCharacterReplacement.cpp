class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26,0);
        int left = 0, maxFreq = 0, maxlen = 0;
        for(int right =0; right<s.length(); right++){
            freq[s[right]-'A']++;
            maxFreq = max(maxFreq, freq[s[right]-'A']);

            if(right-left+1-maxFreq>k){
                freq[s[left]-'A']--;
                left++;
            }

            maxlen = max(maxlen, right-left+1);
        }
        return maxlen;
    }
};

// https://leetcode.com/problems/longest-repeating-character-replacement/
