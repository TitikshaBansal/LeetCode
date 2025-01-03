class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        map<string, int> m;
        int n= s.length();
        vector<string> ans;
        string temp ="";
        for(int i=0; i<n; i++){
            temp += s[i];
            while(temp.length()>10) temp.erase(temp.begin());
            if(temp.length() == 10) m[temp]++;
        }
        for(auto& curr : m){
            if(curr.second >1) ans.push_back(curr.first);
        }
        return ans;
    }
};

// https://leetcode.com/problems/repeated-dna-sequences/
