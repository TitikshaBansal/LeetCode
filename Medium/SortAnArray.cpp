class Solution {
private:
    void merge(vector<int>& arr, int s, int e){
        int mid = s+ (e-s)/2;
        int len1= mid-s+1;
        int len2= e-mid;
        int index=s;
        int *arr1 = new int[len1];
        int *arr2 = new int[len2];
        for(int i=0; i<len1; i++) arr1[i]= arr[index++];
        for(int i=0; i<len2; i++) arr2[i]= arr[index++];
        index=s; 
        int index1=0, index2=0;
        while(index1< len1 && index2<len2){
            if(arr1[index1]<= arr2[index2]) arr[index++]= arr1[index1++];
            else arr[index++]= arr2[index2++];
        }
        while(index1<len1) arr[index++]= arr1[index1++];
        while(index2 <len2) arr[index++]= arr2[index2++];
    }
    void mergeSort(vector<int>& arr, int s, int e){
        if(s>=e) return;
        int mid = s + (e-s)/2;
        mergeSort(arr, s, mid);
        mergeSort(arr, mid+1, e);
        merge(arr, s, e);
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size()-1);
        return nums;
    }
};
