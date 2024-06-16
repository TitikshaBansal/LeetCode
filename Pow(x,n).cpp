class Solution {
public:
    double myPow(double x, int n) {
        if( n== 0){
            return 1;
        }
        double mul= myPow(x, n/2);
        if(n%2==0){
            return mul* mul;
        }
        else return n>0? mul* mul*x :  mul* mul/x;
    }
};
