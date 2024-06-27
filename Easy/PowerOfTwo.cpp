class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0) return false;
        int num= n & (n-1);
        if(num==0)return true;
        return false;
    }
};
