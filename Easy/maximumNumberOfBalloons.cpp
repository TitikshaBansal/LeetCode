class Solution {
public:
    int maxNumberOfBalloons(string text) {
        map<char, int> m = {{'a',0}, {'b',0}, {'l',0}, {'o',0}, {'n',0}};
        for(char i : text) if(m.find(i) != m.end()) m[i]++;
        m['l'] /= 2;
        m['o'] /=2;
        int ans = INT_MAX;
        for(auto i : m ){
            ans = min ( ans, i.second);
        }
        return ans;
    }
};

// https://leetcode.com/problems/maximum-number-of-balloons/
