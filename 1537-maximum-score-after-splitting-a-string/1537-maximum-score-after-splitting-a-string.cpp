class Solution {
public:
    int maxScore(string s) {
        bool flag = false;
        int n = s.size();
        vector<int>pref(n, 0), suff(n, 0);

        if(s[0]=='0') pref[0] = 1;

        for(int i=1; i<s.size(); ++i){
            if(s[i]=='0') pref[i] = pref[i-1]+1;
            else pref[i] = pref[i-1];
        }

        if(s[n-1]=='1') suff[n-1] = 1;

        for(int i=n-2; i>=0; --i){
            if(s[i]=='1') suff[i] = suff[i+1]+1;
            else suff[i] = suff[i+1];
        }
        for(auto it:pref) cout << it << " ";
        cout << endl;
        for(auto it:suff) cout << it << " ";
        int ans = 0;
        for(int i=1; i<n-1; ++i){
            ans = max(ans, suff[i]+pref[i]);
        }
        if(n==2){
            if(s=="00") return 1;
            if(s=="01") return 2;
            if(s=="10") return 0;
            if(s=="11") return 1;
        }
        return ans;
    }
};