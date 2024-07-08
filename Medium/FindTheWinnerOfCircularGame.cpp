class Solution {
public:
    int findTheWinner(int n, int k) {
        if(n==1) return n;
        vector<int> ans;
        for(int i=1; i<=n; i++){
            ans.push_back(i);
        }
        int temp=0;
        while(ans.size()>1){
            int next= (temp+k-1) % ans.size();
            ans.erase(ans.begin()+ next);
            temp= next;
        }
        return ans[0];
    }
};
