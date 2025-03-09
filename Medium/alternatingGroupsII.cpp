class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        int ans = 0;

        int alternate = 1;
        int last = colors[0];

        for(int i = 1; i< n + k -1; i++){
            int index = i%n;
            if(colors[index] == last){
                alternate = 1;
                last = colors[index];
                continue;
            }

            alternate++;
            if(alternate>=k) ans++;
            last = colors[index];
        }
        return ans;
    }
};

// https://leetcode.com/problems/alternating-groups-ii/?envType=daily-question&envId=2025-03-09
