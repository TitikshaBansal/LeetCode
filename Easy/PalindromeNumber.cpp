private:
    long long reverse(int x){
        long long y=0;
        while(x!=0){
            y=(y*10)+(x%10);
            x= x/10;
        }
        return y;
    }
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        int y= reverse(x);
        if(x==y){
            return true;
        }
        return false;
    }

// one more approach
class Solution {
public:
    bool isPalindrome(int x) {
        string num = to_string(x);
        int i =0, e= num.length()-1 ;
        while(i<e){
            if(num[i++] != num[e--]) return false;
        }
        return true;
    }
};

// https://leetcode.com/problems/palindrome-number/
