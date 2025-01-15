class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int ans = 0;
        sort(s.begin(), s.end());
        for(int i : g){
            auto it = lower_bound(s.begin(), s.end(), i);
            if(it != s.end()){
                ans++;
                s.erase(it);
            }
        }
        return ans;
    }
};

// https://leetcode.com/problems/assign-cookies/
