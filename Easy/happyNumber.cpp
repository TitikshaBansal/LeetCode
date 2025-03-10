class Solution {
public:
    int next(int n){
        int ans = 0;
        while(n>0){
            int temp = n% 10;
            ans+= temp*temp;
            n/=10;
        }
        return ans;
    }
    bool isHappy(int n) {
        unordered_set<int> s;
        while(s.find(n) == s.end()){
            s.insert(n);
            n = next(n);
            if(n==1) return true;
        }
        return false;
    }
};

// https://leetcode.com/problems/happy-number/
