class Solution {
private:
    static bool compare(pair<int, int>& a, pair<int, int>& b){
        return (a.second == b.second) ? a.first>b.first : a.second<b.second;
    }
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int, int> m;
        for(int i=0; i< nums.size(); i++){
            m[nums[i]]++;
        }
        vector<pair<int, int>> v;
        for( auto i: m) v.push_back(i);
        sort(v.begin(), v.end(), compare);
        vector<int> ans;
        for(auto i: v){
            for(int j=0; j< i.second; j++) ans.push_back(i.first);
        }
        return ans;
    }
};
