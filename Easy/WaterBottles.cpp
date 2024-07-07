class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans= numBottles;
        int remainder= numBottles;
        while(remainder>= numExchange){
            int temp= remainder/numExchange;
            ans+=temp;
            remainder= remainder%numExchange+temp;
        }
        return ans;
    }
};
