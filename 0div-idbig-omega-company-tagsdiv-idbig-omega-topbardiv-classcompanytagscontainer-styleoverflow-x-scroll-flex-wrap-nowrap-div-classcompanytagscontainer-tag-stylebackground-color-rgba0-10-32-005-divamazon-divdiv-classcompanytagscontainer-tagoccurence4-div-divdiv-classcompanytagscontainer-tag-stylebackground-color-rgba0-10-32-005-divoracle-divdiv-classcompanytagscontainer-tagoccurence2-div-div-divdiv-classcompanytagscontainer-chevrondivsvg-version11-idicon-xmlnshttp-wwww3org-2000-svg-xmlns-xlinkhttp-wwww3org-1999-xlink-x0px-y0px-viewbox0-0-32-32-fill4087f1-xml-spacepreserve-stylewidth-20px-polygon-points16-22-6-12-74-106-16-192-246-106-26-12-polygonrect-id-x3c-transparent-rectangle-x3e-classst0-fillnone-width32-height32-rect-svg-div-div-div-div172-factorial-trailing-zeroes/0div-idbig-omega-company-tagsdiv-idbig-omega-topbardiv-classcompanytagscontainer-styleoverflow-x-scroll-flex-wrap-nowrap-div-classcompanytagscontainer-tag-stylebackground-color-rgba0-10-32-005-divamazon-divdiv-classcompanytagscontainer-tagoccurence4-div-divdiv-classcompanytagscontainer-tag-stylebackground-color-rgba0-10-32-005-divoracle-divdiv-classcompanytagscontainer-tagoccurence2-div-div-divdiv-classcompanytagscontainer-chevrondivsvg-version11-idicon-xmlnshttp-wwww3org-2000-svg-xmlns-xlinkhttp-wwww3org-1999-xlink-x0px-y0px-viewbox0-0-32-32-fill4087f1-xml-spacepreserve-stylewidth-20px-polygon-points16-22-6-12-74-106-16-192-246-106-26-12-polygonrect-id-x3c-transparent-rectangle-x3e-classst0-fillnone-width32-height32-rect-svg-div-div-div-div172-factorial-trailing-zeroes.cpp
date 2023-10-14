class Solution {
public:
    int trailingZeroes(int n) {
         int sum = 0;
        long long int d = 5;
        if(n<5) return 0;
        while(n>=d){
            sum += floor(n/d);
            d *= 5;
        }
        return sum;
    }
};