class Solution {
public:
    int maxDistance(string s, int k) {
        int n = s.size();
        long long ans = 0;
        for (int s_x : {1, -1}) {
            for (int s_y : {1, -1}) {
                long long base = 0;  
                int cntBad = 0;
                for (int i = 0; i < n; i++){
                    char c = s[i];
                    int contribution = 0;
                    int improvement = 0; 
                    if(c == 'E'){
                        contribution = (s_x == 1 ? 1 : -1);
                        improvement = (s_x == 1 ? 0 : 2);
                    } else if (c == 'W') { 
                        contribution = (s_x == 1 ? -1 : 1);
                        improvement = (s_x == 1 ? 2 : 0);
                    }
                    else if(c == 'N'){
                        contribution = (s_y == 1 ? 1 : -1);
                        improvement = (s_y == 1 ? 0 : 2);
                    } else { 
                        contribution = (s_y == 1 ? -1 : 1);
                        improvement = (s_y == 1 ? 2 : 0);
                    }
                    
                    base += contribution;
                    if(improvement == 2) cntBad++;
                    int mods = min(k, cntBad);
                    long long cur = base + 2LL * mods;
                    ans = max(ans, cur);
                }
            }
        }
        return ans;
    }
};

// https://leetcode.com/problems/maximum-manhattan-distance-after-k-changes/
