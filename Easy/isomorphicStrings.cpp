class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) return false;
        unordered_map<char, char> map_s_to_t, map_t_to_s;
        for (int i = 0; i < s.length(); i++) {
            char c1 = s[i], c2 = t[i];
            if (map_s_to_t.count(c1) && map_s_to_t[c1] != c2) return false;
            if (map_t_to_s.count(c2) && map_t_to_s[c2] != c1) return false;
            map_s_to_t[c1] = c2;
            map_t_to_s[c2] = c1;
        }
        return true;
    }
};

// https://leetcode.com/problems/isomorphic-strings/
