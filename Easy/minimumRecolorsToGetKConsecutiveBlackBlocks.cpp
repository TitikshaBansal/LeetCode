class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int count = 0; 
        for (int i = 0; i < k; i++)  if (blocks[i] == 'W') count++;
        
        int ans = count; 
        for (int i = k; i < blocks.length(); i++) {
            if (blocks[i] == 'W') count++;  
            if (blocks[i - k] == 'W') count--;
            
            ans = min(ans, count);
        }
        return ans;
    }
};

// https://leetcode.com/problems/minimum-recolors-to-get-k-consecutive-black-blocks/?envType=daily-question&envId=2025-03-08
