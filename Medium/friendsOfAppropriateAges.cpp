class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        int ans = 0;
        sort(ages.begin(), ages.end()); 
        for (int i = 0; i < ages.size(); ++i) {
            int start = upper_bound(ages.begin(), ages.end(), 0.5 * ages[i] + 7) - ages.begin();
            int end = upper_bound(ages.begin(), ages.end(), ages[i]) - ages.begin();
            if (end > start + 1) { 
                ans += end - start - 1; 
            }
        }
        return ans;
    }
};

// https://leetcode.com/problems/friends-of-appropriate-ages/
