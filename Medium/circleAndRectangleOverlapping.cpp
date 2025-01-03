class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int nearX = max(x1, min(x2, xCenter));
        int nearY = max(y1, min(y2, yCenter));
        int x = pow(nearX-xCenter, 2);
        int y = pow(nearY-yCenter, 2);
        return x+y <= radius*radius;
    }
};

// https://leetcode.com/problems/circle-and-rectangle-overlapping/
