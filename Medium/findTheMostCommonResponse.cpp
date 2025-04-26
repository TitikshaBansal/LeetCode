class Solution {
public:
    string findCommonResponse(vector<vector<string>>& responses) {
        map<string, int> m;
        int maxi = 0;

        for(vector<string> response : responses){
            set<string> s;
            for(string i : response){
                s.insert(i);
            }
            for(string i : s){
                m[i]++;
                maxi = max(maxi, m[i]);
            }
        }

        for(auto& [str, count] : m){
            if(count == maxi) return str;
        }
        return "";
    }
};

// https://leetcode.com/problems/find-the-most-common-response/
