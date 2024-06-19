class Solution {
    // performing mergesort to sort the rest of the array1.
    private:
    void merge(vector<int> &arr1, int s, int e){
        int mid= (s+e)/2;
        int len1= mid-s+1;
        int len2= e-mid;
        int *temp1= new int[len1];
        int *temp2= new int[len2];
        int index=s;
        for(int i=0; i<len1; i++){
            temp1[i]= arr1[index++];
        }
        for(int i=0; i<len2; i++){
            temp2[i]= arr1[index++];
        }
        index=s;
        int index1=0, index2=0;
        while(index1<len1 && index2<len2){
            if(temp1[index1]<temp2[index2]){
                arr1[index++]= temp1[index1++];
            }
            else{
                arr1[index++]= temp2[index2++];
            }
        }
        while(index1<len1){
            arr1[index++]= temp1[index1++];
        }
        while(index2<len2){
            arr1[index++]= temp2[index2++];
        }
        return;
    }
    void mergeSort(vector<int> &arr1, int s, int e){
        if(s>=e){
            return;
        }
        int mid= (s+e)/2;
        mergeSort(arr1, s, mid);
        mergeSort(arr1, mid+1, e);
        merge(arr1,s,e);
    }
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        // traversing through arr1 and comparing it with reference element of array 2 and performing swap function.
        int index1=0;
        for(int i=0; i< arr2.size(); i++){
            int j=0;
            while(j<arr1.size()){
                if(arr1[j]==arr2[i]){
                    swap(arr1[j], arr1[index1]);
                    index1++;
                }
                j++;
            }
        }
        mergeSort(arr1, index1, arr1.size()-1);
        return arr1;
    }
};
