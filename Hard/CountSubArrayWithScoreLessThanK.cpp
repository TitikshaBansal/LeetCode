class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long s=0, e=0;
        long long count=0, sum=0;
        while(s< nums.size() && e<nums.size()){
            sum += nums[e];
            long long len= e-s+1;
            while( sum* len >= k){
                sum -= nums[s];
                len--;
                s++;
            }
            count += e-s+1;
            e++;

        }
        return count;
    }
};
