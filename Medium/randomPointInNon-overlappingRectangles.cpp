class Solution {
public:
    Solution(vector<vector<int>>& rects) : rects(rects) {
        totalArea = 0;
        for (const auto& rect : rects) {
            int width = rect[2] - rect[0] + 1;  // Inclusive range
            int height = rect[3] - rect[1] + 1; // Inclusive range
            totalArea += width * height;       // Total integer points in the rectangle
            areas.push_back(totalArea);        // Store cumulative area
        }
    }
    vector<int> pick() {
        // Step 1: Randomly select a rectangle based on weighted probability
        int randArea = rand() % totalArea; // Random number in the range [0, totalArea - 1]
        int rectIndex = upper_bound(areas.begin(), areas.end(), randArea) - areas.begin();
        
        // Step 2: Generate a random point within the selected rectangle
        const auto& rect = rects[rectIndex];
        int x = rect[0] + rand() % (rect[2] - rect[0] + 1); // Random x-coordinate
        int y = rect[1] + rand() % (rect[3] - rect[1] + 1); // Random y-coordinate
        
        return {x, y};
    }

private:
    vector<vector<int>> rects; // Store the rectangles
    vector<int> areas;         // Cumulative area of rectangles
    int totalArea;             // Total area covered by all rectangles
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */

// https://leetcode.com/problems/random-point-in-non-overlapping-rectangles/
