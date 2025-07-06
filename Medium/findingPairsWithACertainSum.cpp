class FindSumPairs {
public:
    vector<int> nums2;
    unordered_map<int, int> m1, m2;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        for(int num : nums1) m1[num]++;
        this->nums2 = nums2;
        for(int num : nums2) m2[num]++;
    }
    
    void add(int index, int val) {
        m2[nums2[index]]--;
        nums2[index] += val;
        m2[nums2[index]]++;
    }
    
    int count(int tot) {
        int ans = 0;
        for(auto [num, count] : m1){
            if(m2.find(tot-num) != m2.end()){
                ans += count*m2[tot-num];
            }
        }
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */

// https://leetcode.com/problems/finding-pairs-with-a-certain-sum/?envType=daily-question&envId=2025-07-06
