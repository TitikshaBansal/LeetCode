class Solution {
public:
    int maxContainers(int n, int w, int maxWeight) {
        int low = 0, high = n * n; 

        while (low <= high) { 
            int mid = low + (high - low) / 2;
            if (mid * w <= maxWeight) low = mid + 1;
            else high = mid - 1;
        }
        
        return high;
    }
};

// https://leetcode.com/problems/maximum-containers-on-a-ship/
