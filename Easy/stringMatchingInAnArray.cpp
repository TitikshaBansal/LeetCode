class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;
        for(int i=0; i<words.size(); i++){
            for(int j=0; j<words.size(); j++){
                if(i!=j && words[j].find(words[i]) != string::npos){
                    ans.push_back(words[i]);
                    break;
                }
            }
        }
        return ans;
    }
};

// https://leetcode.com/problems/string-matching-in-an-array/?envType=daily-question&envId=2025-01-07
