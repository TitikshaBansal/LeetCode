class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len= digits.size()-1;
        digits[len]++;
        int carry=0;
        if(digits[len]>9){
            carry= digits[len]/10;
            digits[len]%=10;
        }
        for(int i= len-1; i>=0; i--){
            int temp = digits[i]+carry;
            if(temp>9){
                carry= temp/10;
                temp%=10;
            }
            else carry=0;
            digits[i]= temp;
        }
        if (carry !=0) digits.insert(digits.begin(), carry);
        return digits;
    }
};
