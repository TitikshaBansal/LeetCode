
class Solution {
public:
    bool hasMatch(string s, string p) {
        int starPos = p.find('*');
        
        // Split the pattern into prefix and suffix
        string prefix = p.substr(0, starPos);
        string suffix = p.substr(starPos + 1);
        
        // Check all possible substrings in `s`
        int index1 = s.find(prefix);
        if(index1 == string::npos) return false;
        index1 += prefix.length();
        int index2 = s.find(suffix, index1);
        if(index2 == string::npos) return false;
        
        return true;
    }
};

// https://leetcode.com/problems/substring-matching-pattern/
