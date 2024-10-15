class Solution {
public:
    long long minimumSteps(string s) {
        long long cnt = 0;
        long long ones = 0;

        for(int i=0; i<s.size(); ++i) {
            s[i] == '1' ? ones++ : cnt+=ones;
        }
        return cnt;
    }
};