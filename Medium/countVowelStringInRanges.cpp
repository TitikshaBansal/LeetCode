class Solution {
private:
    bool isValid(string word){
        int n= word.length()-1;
        return ((word[0] == 'a'|| word[0] == 'e'|| word[0] == 'i'|| word[0] == 'o'|| word[0] == 'u') &&
        (word[n] == 'a'|| word[n] == 'e'|| word[n] == 'i'|| word[n] == 'o'|| word[n] == 'u'));
    }
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> ans;
        int n= words.size();
        vector<int> prefixSum(n+1, 0);
        for(int i=0; i<n; i++) {
            prefixSum[i+1] = prefixSum[i] + (isValid(words[i]) ? 1:0) ;
        }
        for(vector<int> query : queries){
            ans.push_back(prefixSum[query[1] + 1] - prefixSum[query[0]]);
        }
        return ans;
    }
};

// https://leetcode.com/problems/count-vowel-strings-in-ranges/?envType=daily-question&envId=2025-01-02
