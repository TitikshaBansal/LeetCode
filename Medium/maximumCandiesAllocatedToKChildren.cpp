class Solution {
public:
    bool check(vector<int> candies, long long k, int num){
        long long int children = 0;
        for(int candy:candies){
            children += candy/num;
        }
        return children >= k;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int maxi = 0;
        for(int candy : candies) maxi = max(maxi, candy);

        int left = 0, right = maxi;

        while(left<right){
            int mid = left + 1+ (right-left)/2;
            if(check(candies, k, mid)) left = mid;
            else right = mid-1;
        }

        return left;
    }
};

// https://leetcode.com/problems/maximum-candies-allocated-to-k-children/?envType=daily-question&envId=2025-03-14
