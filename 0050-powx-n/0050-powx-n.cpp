class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;

        long long m = n;
        if(m<0) m *= -1;

        while(m > 0){
            if(m%2){
                ans *= x;
                m--;
            } else {
                x = x*x;
                m /= 2;
            }
        }
        if(n<0) return 1.0/ans;
        return ans;
    }
};