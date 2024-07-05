class Solution {
public:
    int largestInteger(int num) {
        vector<char> odd;
        vector<char> even;
        string str= to_string(num);
        for(int i=0; i<str.length(); i++){
            int num= str[i]-'0';
            if(num%2==0) even.push_back(str[i]);
            else odd.push_back(str[i]);
        }
        string ans="";
        sort(odd.begin(), odd.end(), greater<int>());
        sort(even.begin(), even.end(), greater<int>());
        int index1=0, index2=0;
        for(int i=0; i<str.length(); i++){
            int num= str[i]-'0';
            if(num%2==0) ans.push_back(even[index1++]);
            else ans.push_back(odd[index2++]);
        }
        return stoi(ans);
    }
};
