class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> hashMap;
        hashMap[0] = -1;
        int maxLength = 0, sum = 0;

        for(int i = 0; i < nums.size(); i++) {
            sum += (nums[i] == 0) ? -1 : 1;
            if(hashMap.find(sum) != hashMap.end()) {
                maxLength = max(maxLength, i - hashMap[sum]);
            } else {
                hashMap[sum] = i;
            }
        }

        return maxLength;
    }
};
