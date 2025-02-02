class Solution {
public:
    int maxDifference(string s) {
        int n = s.length();
        vector<int> freq(26,0);
        for(char i : s) freq[i-'a']++;
        int even =n, odd = 0;
        for(int i : freq){
            if(i==0) continue;
            else if(i%2 == 0) even = min(even, i);
            else odd = max(odd, i);
        }
        return odd-even;
    }
};

// https://leetcode.com/problems/maximum-difference-between-even-and-odd-frequency-i/
