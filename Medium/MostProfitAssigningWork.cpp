class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        // initialising map to store difficulty as key and maximum profit corresponding to the difficulty as value.
        map<int , int> m;
        // sorting workers for easy traversal for comparison
        sort(worker.begin(), worker.end());

        // storing values in map.
        for(int i=0; i< difficulty.size(); i++){
            if (m.find(difficulty[i]) != m.end()) {
                m[difficulty[i]] = max(m[difficulty[i]], profit[i]);
            } else {
                m[difficulty[i]] = profit[i];
            }
        }

        // traversing through map for each worker and calculating max profit possible.
        int ans=0, best=0;
        // Iterator to traverse through jobs in the map
        auto job = m.begin();
        for( int i: worker){
            while( job != m.end() && i>= job->first){
                best= max(best, job->second);
                job++;
            }
            ans+=best;
        }

        return ans;
    }
};
