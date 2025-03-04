class Solution {
    bool help(int i, int curr, int n) {
        if(i > 16) return false;
        if (curr == n) {
            return true;
        }
        if(curr > n) return false;
        long long x = pow(3, i);
        bool notPick = help(i+1, curr, n);
        bool pick = help(i+1, curr+x, n);

        return notPick || pick;
    }

public:
    bool checkPowersOfThree(int n) {
        return help(0, 0, n);
        
    }
};