class Solution {
public:
    int lengthOfLastWord(string s) {
        int e= s.length()-1;
        while(e >= 0 && s[e] == ' ') e--;
        int len=0;
        while(e >= 0 && s[e]!= ' ' ){
            len++;
            e--;
        }
        return len;
    }
};
