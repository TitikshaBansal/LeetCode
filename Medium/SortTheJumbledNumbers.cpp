class Solution {
private:
    static bool compare(pair<int, long long> &a, pair<int, long long> &b){
        return (a.second < b.second); 
    }
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int, long long>> v;
        for( int num : nums){
            int temp= num;
            int val=0;
            int place=1;
            if(temp == 0) val= mapping[0];
            else{
                while(temp!=0){
                val= val + mapping[temp%10]*place;
                place*=10;
                temp/=10;
                }
            }
            v.push_back({num, val});
        }
        sort(v.begin(), v.end(), compare);
        vector<int> ans;
        for(auto i : v){
            ans.push_back(i.first);
        }
        return ans;
    }
};
