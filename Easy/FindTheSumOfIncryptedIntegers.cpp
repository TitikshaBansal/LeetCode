class Solution {
public:
    int sumOfEncryptedInt(vector<int>& nums) {
        int ans=0;
        for(int i=0; i< nums.size(); i++){
            string str= to_string(nums[i]);
            int len= str.length();
            sort(str.begin(), str.end());
            int num= str[len-1];
            string final(len,num);
            int n= stoi(final);
            ans+=n;
        }
        return ans;
    }
};
