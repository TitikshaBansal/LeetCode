class Solution {
public:
    bool canEat(vector<int>& piles, int h, int k){
        double req = 0;
        for(int num : piles){
            req += ceil((double)num/k);
            if(req > h) return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int s = 0, e = *max_element(piles.begin(), piles.end());
        int ans = -1;
        while(s <= e){
            int mid = s + (e-s)/2;
            if(canEat(piles, h, mid)){
                ans = mid;
                e = mid-1;
            }
            else s = mid + 1;
        }
        return ans;
    }
};

// https://leetcode.com/problems/koko-eating-bananas/
