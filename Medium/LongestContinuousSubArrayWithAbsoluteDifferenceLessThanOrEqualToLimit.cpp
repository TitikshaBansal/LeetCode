class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int length =0;
        int s=0;
        deque<int> maxi;
        deque<int> mini;
        for(int i=0; i< nums.size(); i++){
            while(!maxi.empty() && nums[i] > maxi.back()){
                maxi.pop_back();
            }
            maxi.push_back(nums[i]);
            while(!mini.empty() && nums[i] < mini.back()){
                mini.pop_back();
            }
            mini.push_back(nums[i]);

            while(maxi.front()- mini.front() > limit){
                if(nums[s] == maxi.front()) maxi.pop_front();
                if(nums[s] == mini.front()) mini.pop_front();
                s++;
            }
            length= max(length, i-s+1);
        }
        return length;
    }
};
