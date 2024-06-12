class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        long long ans=0;
        //ignoring blank spaces
        while(i<s.size() && s[i]==' '){
            i++;
        }
        int sign=1;
        if(i < s.size() && (s[i] == '-' || s[i] == '+')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }
        //ignoring leading zeroes.
        while(s[i]=='0'){
            i++;
        }
        while(i<s.length() && isdigit(s[i])){
                ans = ans * 10 + (s[i] - '0');
            
            // Rounding
            if(sign == 1 && ans > INT_MAX) {
                return INT_MAX;
            } 
            else if(sign == -1 && -ans < INT_MIN) {
                return INT_MIN;
            }
            
            i++;
        }
        ans*=sign;
        if(ans < INT_MIN) return INT_MIN;
        if(ans > INT_MAX) return INT_MAX;
        return int(ans);
    }
};
