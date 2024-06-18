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
