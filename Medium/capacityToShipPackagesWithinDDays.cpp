class Solution {
public:
    bool isPossible(vector<int>& weights, int days, int maxweight) {
        int currentDay = 1;
        int currentWeight = 0;
        for (int w : weights) {
            if (currentWeight + w > maxweight) {
                currentDay++;
                currentWeight = 0;
            }
            currentWeight += w;
            if (currentDay > days) return false;
        }
        return true;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int s = *max_element(weights.begin(), weights.end());
        int e = accumulate(weights.begin(), weights.end(), 0);
        int ans = e;

        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (isPossible(weights, days, mid)) {
                ans = mid;
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }

        return ans;
    }
};

// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
