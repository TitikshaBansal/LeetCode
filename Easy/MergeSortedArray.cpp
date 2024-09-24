class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> temp(m);
        for(int i=0; i<m; i++){
            temp[i]=nums1[i];
        }
        int index1=0, index2=0, index=0;
        while(index1<m && index2<n){
            if(temp[index1]< nums2[index2]) nums1[index++]= temp[index1++];
            else nums1[index++]= nums2[index2++];
        }
        while(index1<m){
            nums1[index++]= temp[index1++];
        }
        while(index2<n){
            nums1[index++]= nums2[index2++];
        }
        return;
    }
};

// optimized solution
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int index1 = m - 1; 
        int index2 = n - 1; 
        int mergeIndex = m + n - 1; 
        while (index1 >= 0 && index2 >= 0) {
            if (nums1[index1] > nums2[index2]) {
                nums1[mergeIndex--] = nums1[index1--];
            } else {
                nums1[mergeIndex--] = nums2[index2--];
            }
        }
        while (index2 >= 0) {
            nums1[mergeIndex--] = nums2[index2--];
        }

    }
};

// https://leetcode.com/problems/merge-sorted-array/
