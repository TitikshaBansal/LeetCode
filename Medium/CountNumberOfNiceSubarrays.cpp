class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        for(int i=0; i< nums.size(); i++){
            nums[i]= nums[i]%2;
        }
        int s=0, e=0;
        int count=0;
        long long sum=0;
        while(s<=e && e<nums.size()){
            sum += nums[e];
            while (s<=e && sum>k){
                sum -= nums[s];
                s++;
            }
            if(sum==k){
                int temp= s;
                while(temp<=e && sum==k){
                    count++; 
                    if(temp<e){
                        sum -= nums[temp];
                    }
                    temp++;
                }
                sum=k;
            }
            e++;
        }
        return count;
    }
};
