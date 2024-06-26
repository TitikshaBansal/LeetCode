class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        sort(nums1.begin(), nums1.end());
        int e= nums1.size();
        if(e%2==1){
            int mid= e/2;
            return nums1[mid];
        }
        else{
            int mid= e/2-1;
            double median= double(nums1[mid]+nums1[mid+1])/2;
            return median;
        }
        
    }
};
