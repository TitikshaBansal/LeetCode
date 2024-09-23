class Solution {
    private:
    void merge(vector<int>& nums, int s, int e){
        int mid= (s+e)/2;
        int len1= mid-s+1;
        int len2= e-mid;
        vector<int> arr1(len1);
        vector<int> arr2(len2);
        int index=s;
        for(int i=0; i<len1;i++){
            arr1[i]=nums[index++];
        }
        for(int i=0; i<len2;i++){
            arr2[i]=nums[index++];
        }
        index=s;
        int index1=0, index2=0;
        while(index1<len1 && index2<len2){
            if(arr1[index1]< arr2[index2]){
                nums[index++]=arr1[index1++];
            }
            else{
                nums[index++]=arr2[index2++];
            }
        }
        while(index1<len1){
            nums[index++]=arr1[index1++];
        }
        while(index2<len2){
            nums[index++]=arr2[index2++];
        }
    }
    void mergeSort(vector<int>& nums, int s, int e){
        if(s>=e){
            return;
        }
        int mid= (s+e)/2;
        mergeSort(nums, s, mid);
        mergeSort(nums, mid+1, e);
        merge(nums, s, e);
    }
public:
    void sortColors(vector<int>& nums) {
        int s=0;
        int e= nums.size()-1;
        mergeSort(nums,s,e);
        
    }
};

// better approach oh O(n) complexity..............
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero =0, one =0, two =0;
        for(int num : nums) {
            if(num == 0) zero++;
            else if(num == 1) one++;
            else two++;
        }
        int index =0;
        while(zero!=0){
            nums[index++]=0;
            zero--;
        }
        while(one!=0){
            nums[index++]=1;
            one--;
        }
        while(two!=0){
            nums[index++]=2;
            two--;
        }
    }
};
