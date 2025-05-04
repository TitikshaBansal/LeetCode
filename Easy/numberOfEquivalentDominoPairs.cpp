class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<pair<int, int>, int> m;
        int count=0;

        for(vector<int> domino : dominoes){
            int u = domino[0], v= domino[1];

            pair<int, int> key = {min(u, v), max(u, v)};
            count += m[key];
            m[key]++;
        }
        return count;
    }
};

// https://leetcode.com/problems/number-of-equivalent-domino-pairs/?envType=daily-question&envId=2025-05-04
