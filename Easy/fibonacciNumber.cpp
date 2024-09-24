class Solution {
public:
    int fib(int n) {
        if (n < 2) return n;
        int ans;
        int a = 0, b = 1;
        for(int i = 2 ; i <= n ; ++i){
            ans = a + b ;
            a = b ;
            b = ans ;
        }
        return ans;
    }
};


// recursive approach
class Solution {
public:
    int fib(int n) {
        if(n == 0) return 0;
        if(n<3) return 1;
        return fib(n-1) + fib(n-2);
    }
};

// https://leetcode.com/problems/fibonacci-number/
