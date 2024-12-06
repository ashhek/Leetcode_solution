class Solution {
public:
    int powerCheck(int n) {
        int pow = 1;
        while(pow < n) {
            pow *= 2;
        }
        return pow;
    }
    int smallestNumber(int n) {
        int x = powerCheck(n+1);
        return x-1;
    }
};