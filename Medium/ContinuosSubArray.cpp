bool checkSubarraySum(vector<int>& nums, int k) {
        std::unordered_map<int, int> mods;
    mods[0] = -1; // Handle the case where the subarray starts from index 0
    int cumSum = 0;

    for (int i = 0; i < nums.size(); ++i) {
        cumSum += nums[i];
        if (k != 0) {
            cumSum %= k;
        }

        if (mods.count(cumSum)) {
            if (i - mods[cumSum] > 1) {
                return true; // Found a subarray
            }
        } else {
            mods[cumSum] = i;
        }
    }
    return false;
    }
