class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        queue<int> q; 
        int i=0;
        while(i<arr.size() && q.size()!=3){
            if(arr[i]%2==1)q.push(i);
            if(!q.empty()) {
                while(q.back() - q.front()>2) {
                    q.pop();
                }
            }
            i++;
        }
        if(q.size()==3) return true;
        return false;
    }
};
