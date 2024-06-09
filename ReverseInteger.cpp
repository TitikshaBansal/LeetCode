int reverse(int x) {
        vector<double> arr;
        int num= abs(x);
        int temp;
        while(num!=0){
            temp=num%10;
            arr.push_back(temp);
            num= num/10;
        }
        int ans= 0;
        int len= arr.size();
        for(int i=0; i<len; i++){
            if( ans>INT_MAX/10 || ans< INT_MIN/10){
                return 0;
            }
            ans= ans*10 + arr[i];
        }
        if (x<0){
            ans= 0-ans;
        }
        
        return ans;
        
        
        
    }
