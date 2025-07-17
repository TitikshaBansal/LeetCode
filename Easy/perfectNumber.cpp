class Solution {
public:
    bool checkPerfectNumber(int n) {
        if (n <= 1) return false;
        int sum = 1;
        for(int i = 2; i<sqrt(n); i++){
            if(n%i == 0){
                sum += i;
                sum += n/i;
            }
        }
        return sum == n;
    }
};

// https://leetcode.com/problems/perfect-number/
