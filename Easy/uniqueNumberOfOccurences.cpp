class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> m;
        for(int num : arr) m[num]++;

        unordered_set<int> s;
        for(auto [ _ , count] : m){
            if(s.count(count)) return false;
            s.insert(count);
        }
        return true;
    }
};

// https://leetcode.com/problems/unique-number-of-occurrences/
