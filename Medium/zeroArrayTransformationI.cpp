class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> diff(n+1, 0);
        for(vector<int> query : queries){
            int s = query[0];
            int e = query[1];
            diff[s]++;
            diff[e+1]--;
        }
        vector<int> op;
        int curr = 0;
        for(int d : diff){
            curr += d;
            op.push_back(curr);
        }
        for(int i=0; i<n; i++){
            if(op[i] < nums[i]) return false;
        }
        return true;
    }
};


// https://leetcode.com/problems/zero-array-transformation-i/?envType=daily-question&envId=2025-05-20
