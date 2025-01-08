class Solution {
private:
    bool isPrefixAndSuffix(string str1, string str2){
        int n1 = str1.length();
        int n2 = str2.length();
        if(n1>n2) return false;
        if(str2.substr(0, n1) == str1 && str2.substr(n2 - n1, n1) == str1) return true;
        return false;
    }
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int ans =0;
        for(int i=0; i<words.size()-1; i++){
            for(int j=i+1; j<words.size(); j++){
                if(isPrefixAndSuffix(words[i], words[j])) ans++;
            }
        }
        return ans;
    }
};

// https://leetcode.com/problems/count-prefix-and-suffix-pairs-i/?envType=daily-question&envId=2025-01-08
