class DataStream {
private:
    int value; 
    int k; 
    int count; 

public:
    DataStream(int value, int k) {
        this->value = value;
        this->k = k;
        this->count = 0;
    }
    bool consec(int num) {
        if (num == value) {
            count++;
        } else {
            count = 0; 
        }
        return count >= k;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */

// https://leetcode.com/problems/find-consecutive-integers-from-a-data-stream/
