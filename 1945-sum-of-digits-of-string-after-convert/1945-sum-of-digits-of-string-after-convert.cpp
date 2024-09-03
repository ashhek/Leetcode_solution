class Solution {
    int help(int x) {
        int res = 0;
         while(x) {
            res += x%10;
            x /= 10;
         }
         return res;
    }
public:
    int getLucky(string s, int k) {
        int n = s.size();
        k--;

        int sum = 0;
        for(char ch : s) {
            int x = (ch-'a') + 1;
            while(x) {
                sum += (x%10);
                x /= 10;
            }
        }
        if(k==0) return sum;

        for(int i=0; i<k; ++i) {
            cout << sum << endl;
            sum = help(sum);
        }
        return sum;
    }
};