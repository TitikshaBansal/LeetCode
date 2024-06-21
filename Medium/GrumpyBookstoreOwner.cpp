class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int happy=0;
        for(int i=0; i< customers.size(); i++){
            if(grumpy[i]==0) happy+=customers[i];
        }
        int maxCus = 0;
        int temp = 0;
        for (int i = 0; i < minutes; i++) {
            if (grumpy[i] == 1) temp += customers[i];
        }
        maxCus = temp;
        for (int i = minutes; i < grumpy.size(); i++) {
            if (grumpy[i] == 1) temp += customers[i];
            if (grumpy[i - minutes] == 1) temp -= customers[i - minutes];
            maxCus = max(maxCus, temp);
        }
        happy+=maxCus;
        return happy;

        
    }
};
