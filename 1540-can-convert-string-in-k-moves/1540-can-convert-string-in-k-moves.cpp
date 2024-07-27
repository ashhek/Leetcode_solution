class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        int n = s.size();
        int m = t.size();

        if(n!=m) return false;

        int mult[26] = {0};

        for(int i=0; i<n; ++i){
            int shift = t[i] - s[i] + ((t[i] - s[i]) < 0 ? 26 : 0);

            if(shift !=0 && shift + mult[shift]*26 > k)
            return false;

            mult[shift]++;
        }
        return true;
    }
};