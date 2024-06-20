New topic
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int s=0;
        int e=nums.size()-1;
        while(s<=e){
            int mid= s+ (e-s)/2;
            if(nums[mid]> target) e=mid-1;
            else if(nums[mid]<target) s= mid+1;
            else{
                if(nums[s]!=target) s++;
                if(nums[e]!=target) e--;
                if(nums[s]==target && nums[e]==target) return {s,e};

            }
        }
        return {-1,-1};
    }
};
