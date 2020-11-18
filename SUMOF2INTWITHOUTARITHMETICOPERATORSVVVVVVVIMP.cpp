class Solution {
public:
    int getSum(int a, int b) {
        unsigned int car=1;
        while(car)
        {
            car = a&b;
            a = a^b;
            b = car<<1;
        }
        return a;
        
    }
};