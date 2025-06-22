class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        int n = s.length()/k;
        if(s.length()%k != 0) n++;
        int idx =0;
        for(int i=0; i<n; i++){
            string curr = s.substr(idx, k);
            idx+=k;
            if(i == n-1){
                int len = k-curr.length();
                curr.append(len, fill);
            }
            ans.push_back(curr);
        }
        return ans;
    }
};


// https://leetcode.com/problems/divide-a-string-into-groups-of-size-k/?envType=daily-question&envId=2025-06-22
