class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
     vector<int>xorTable(arr.size()+1,0);
     for(int i=0;i<arr.size();i++){
        xorTable[i+1]=arr[i]^xorTable[i];
     }
     vector<int>ans;   
     for(int i=0;i<queries.size();i++){
        ans.push_back(xorTable[queries[i][1]+1]^xorTable[queries[i][0]]);
     }
     return ans;
    }
};
