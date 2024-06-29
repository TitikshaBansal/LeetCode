class Solution {
private:
    void PrimeFactors(int n, map<int,int> &m) {
        while (n%2 == 0){
            m[2]++;
            n = n/2;
        }
        for (int i = 3; i <= sqrt(n); i = i+2){
            while (n%i == 0){
                m[i]++;
                n = n/i;
            }
        }
        if (n > 2)
        m[n]++;
    }
public:
    int distinctPrimeFactors(vector<int>& nums) {
        map<int,int> m;
        for(int i=0; i< nums.size(); i++){
            PrimeFactors(nums[i], m);
        }
        return m.size();
    }
};
