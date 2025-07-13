class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        int ans = 0;
        int n = players.size();
        int m = trainers.size();
        int i = 0, j = 0;
        while(i<n && j < m){
            while(j < m && trainers[j] < players[i]) j++;
            if(i < n && j < m && players[i] <= trainers[j]){
                ans++;
                i++;
                j++;
            }
        }
        return ans;
    }
};

// https://leetcode.com/problems/maximum-matching-of-players-with-trainers/?envType=daily-question&envId=2025-07-13
