class Solution {
private:
    int add(int a){
        int sum=0;
        while(a!=0){
            sum= sum+(a%10);
            a/=10;
        }
        return sum;
    }
public:
    int maximumSum(vector<int>& nums) {
        map<int, vector<int>> m;
        for(int i=0; i< nums.size(); i++){
            int sum= add(nums[i]);
            m[sum].push_back(nums[i]);
        }
        int ans= -1;
        for(auto i: m){
            if(i.second.size() > 1){
                sort(i.second.begin(), i.second.end());
                int e= i.second.size()-1;
                int temp = i.second[e] + i.second[e-1];
                ans= max(ans, temp);
            }
        }
        return ans;
    }
};
