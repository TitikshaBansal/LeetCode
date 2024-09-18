class Solution {
public:
    struct comp { 
        bool operator()(int a, int b) const
        { 
            string num1 = to_string(a);
            string num2 = to_string(b);
            return num1 + num2 > num2 + num1;
        }
    }; 
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), comp());
        if (nums[0] == 0) return "0";
        string ans = "";
        for(int num : nums){
            ans+= to_string(num);
        }
        return ans;
    }
};
