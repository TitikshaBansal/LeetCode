class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<int> front(2*k+1,0),curr(2*k+1,0);
        for(int j=0;j<2*k+1;j++){
            front[j]=0;
        }
        for(int i=0;i<n+1;i++){
            front[2*k]=0;
        }
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<2*k;j++){
                int profit=0;
                if(j%2==0){
                    int pick=-prices[i]+front[j+1];
                    int notPick=0+front[j];
                    profit=max(pick,notPick);
                }
                else{
                    int pick=prices[i]+front[j+1];
                    int notPick=0+front[j];
                    profit=max(pick,notPick);
                }
                curr[j]=profit;
            }
            front=curr;
        }
        return front[0];
    }
};

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
