class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.size();
        int ans = 0;
        
        int left = 0, right = n - 1;
        while (left < n && directions[left] == 'L') left++;
        while (right >= 0 && directions[right] == 'R') right--;
        
        for (int i = left; i <= right; i++) {
            if (directions[i] != 'S') {
                ans++;
            }
        }
        
        return ans;
    }
};

// https://leetcode.com/problems/count-collisions-on-a-road/
