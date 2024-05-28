class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        vector<int>diff;

        for(int i=0; i<s.size(); ++i){
            diff.push_back(abs(s[i]-t[i]));
        }
        int len = 0, sum = 0;
        for(int i=0, j=0; j<diff.size(); ++j){
            sum += diff[j];

            while(sum>maxCost){
                sum -= diff[i];
                i++;
            }

            len = max(len, j-i+1);
        }
        return len;
    }
};