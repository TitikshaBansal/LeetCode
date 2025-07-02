class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());
        int radius = 0;
        for (int house : houses) {
            radius = max(radius, findClosestHeater(house, heaters));
        }
        return radius;
    }

    int findClosestHeater(int house, vector<int>& heaters) {
        int left = 0, right = heaters.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (heaters[mid] < house) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        int dist1 = (left < heaters.size()) ? abs(heaters[left] - house) : INT_MAX;
        int dist2 = (right >= 0) ? abs(heaters[right] - house) : INT_MAX;
        return min(dist1, dist2);
    }
};

// https://leetcode.com/problems/heaters/
