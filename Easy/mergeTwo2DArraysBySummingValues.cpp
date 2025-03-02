class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>> ans;
        int n1= nums1.size(), n2= nums2.size();
        int i= 0, j =0;
        while(i<n1 && j<n2){
            if(nums1[i][0] == nums2[j][0]){
                ans.push_back({nums1[i][0], nums1[i][1]+ nums2[j][1]});
                i++;
                j++;
            }
            else if(nums1[i][0] < nums2[j][0])  {
                ans.push_back(nums1[i]);
                i++;
            } 
            else{
                ans.push_back(nums2[j]);
                j++;
            }      
        }
        while(i<n1) ans.push_back(nums1[i++]);
        while(j<n2) ans.push_back(nums2[j++]);
        return ans;
    }
};

// https://leetcode.com/problems/merge-two-2d-arrays-by-summing-values/?envType=daily-question&envId=2025-03-02
