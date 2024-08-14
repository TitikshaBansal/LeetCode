class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        map<char, int> m;
        for(char it : s) m[it]++;
        for(char it : t){
            if(m.find(it) != m.end() && m[it]>0) {
                m[it]--;
                continue;
            }
            return false;
        }
        return true;
    }
};
