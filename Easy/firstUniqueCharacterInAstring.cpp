class Solution {
public:
    int firstUniqChar(string s) {
        int ans = INT_MAX;
        map<char, vector<int>> m;
        for(int i=0; i<s.length(); i++){
            m[s[i]].push_back(i);
        }
        for(auto i: m){
            if(i.second.size() == 1){
                ans = min(ans, i.second[0]);
            }
        }
        return ans==INT_MAX ? -1:ans;
    }
};

// https://leetcode.com/problems/first-unique-character-in-a-string/
