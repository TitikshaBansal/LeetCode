class Solution {
    private:
        bool canMake(vector<int> & bloomDay, int mid, int m, int k){
            int total=0;
            for (int i = 0; i < bloomDay.size(); i++) {
            int count = 0;
            while (i < bloomDay.size() && count < k && bloomDay[i] <= mid) {
                count++;
                i++;
            }

            if (count == k) {
                total++;
                i--;
            }

            if (total >= m) {
                return true;
            }
        }

        return false;

        }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n= bloomDay.size();
        if(n < (long long)m*k) return -1;
        int s=0, e= pow(10,9);

        while(s<e){
            int mid= s+ (e-s)/2;
            if (canMake(bloomDay, mid, m, k)) e= mid;
            else s= mid+1;
        }
        return s;
        
    }
};
