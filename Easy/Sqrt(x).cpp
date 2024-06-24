class Solution {
public:
    int mySqrt(int x) { 
        if(x==0 || x==1) return x;
        long long guess = x / 2;
        while (true) {
            long long new_guess = (guess + x / guess) / 2;
            if (new_guess >= guess) {
                return (int) guess;
            }
            guess = new_guess;
        }
    }
};
