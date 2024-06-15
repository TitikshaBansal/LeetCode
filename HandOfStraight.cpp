class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize!=0){
            return false;
        }
        map<int,int> m;
        for (int card : hand) {
            m[card]++;
        }
        for (auto& [card,count]: m) {
            if (count > 0) {
                for (int i = 1; i<groupSize; i++) {
                    if (m[card+i] < count) return false;
                    m[card+i] -= count;
                }
            }
        }
        return true;
    }
};
