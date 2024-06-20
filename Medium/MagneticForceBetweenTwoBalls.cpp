class Solution {
    private:
    bool check(vector<int> & position, int mid, int m){
        int count=1;
        int last= position[0];
        for( int i=0; i< position.size(); i++){
            if( position[i]- last>= mid){
                count++;
                last= position[i];
            }
            if(count>=m) return true;
        }
        return false;
    }
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int s=1, ans=1; 
        int e= (position.back()-position[0])/ (m-1);

        while(s<=e){
            int mid= s+ (e-s)/2;
            if(check(position, mid, m)){
                ans= mid;
                s= mid+1;
            }
            else e= mid-1;
        }
        return ans;
        
    }
};
