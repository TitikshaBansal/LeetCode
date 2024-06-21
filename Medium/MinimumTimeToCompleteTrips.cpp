class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long s=0;
        long long e = (long long)*max_element(time.begin(), time.end()) * totalTrips;
        while(s<=e){
            long long mid= s+(e-s)/2;
            long long count=0;
            for(int i=0; i<time.size(); i++){
                if(time[i]<= mid){
                    count+= (mid/time[i]);
                }
            }
            if(count>=totalTrips) e= mid-1;
            else s= mid+1;

        }
        return s;
    }
};
