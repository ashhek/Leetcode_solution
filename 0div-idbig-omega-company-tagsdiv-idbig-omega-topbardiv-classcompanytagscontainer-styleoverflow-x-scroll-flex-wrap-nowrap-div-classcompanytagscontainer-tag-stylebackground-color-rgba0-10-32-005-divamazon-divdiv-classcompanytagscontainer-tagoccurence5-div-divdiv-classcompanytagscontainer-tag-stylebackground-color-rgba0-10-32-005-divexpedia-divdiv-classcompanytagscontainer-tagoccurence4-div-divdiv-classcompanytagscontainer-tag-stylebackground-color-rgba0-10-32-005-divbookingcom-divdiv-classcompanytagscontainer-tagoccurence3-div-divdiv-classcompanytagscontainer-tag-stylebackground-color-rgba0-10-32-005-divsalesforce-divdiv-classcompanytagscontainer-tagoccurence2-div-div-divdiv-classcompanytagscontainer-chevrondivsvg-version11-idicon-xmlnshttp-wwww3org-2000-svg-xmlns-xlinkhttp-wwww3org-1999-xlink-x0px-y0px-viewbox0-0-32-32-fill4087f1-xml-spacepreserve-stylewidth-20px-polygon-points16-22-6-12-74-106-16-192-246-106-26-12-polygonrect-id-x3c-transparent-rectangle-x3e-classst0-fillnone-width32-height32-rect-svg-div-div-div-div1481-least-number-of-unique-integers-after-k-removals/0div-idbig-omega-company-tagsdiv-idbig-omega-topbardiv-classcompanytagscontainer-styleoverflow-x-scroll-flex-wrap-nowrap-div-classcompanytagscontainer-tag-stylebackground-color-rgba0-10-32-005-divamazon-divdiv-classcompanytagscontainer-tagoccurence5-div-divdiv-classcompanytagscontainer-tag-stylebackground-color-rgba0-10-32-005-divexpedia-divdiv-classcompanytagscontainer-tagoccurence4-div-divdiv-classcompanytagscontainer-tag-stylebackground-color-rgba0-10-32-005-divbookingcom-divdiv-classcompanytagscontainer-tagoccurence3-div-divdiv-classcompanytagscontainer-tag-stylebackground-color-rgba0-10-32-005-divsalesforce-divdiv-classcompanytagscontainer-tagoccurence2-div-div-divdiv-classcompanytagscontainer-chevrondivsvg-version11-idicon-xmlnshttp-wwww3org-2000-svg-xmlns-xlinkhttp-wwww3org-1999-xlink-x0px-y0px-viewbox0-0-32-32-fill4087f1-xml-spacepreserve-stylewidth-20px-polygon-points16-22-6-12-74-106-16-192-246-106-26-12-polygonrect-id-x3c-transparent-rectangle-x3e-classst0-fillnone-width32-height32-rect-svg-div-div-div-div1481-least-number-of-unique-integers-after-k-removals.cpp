class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int>v;
        map<int,int>mp;
        for(int i=0;i<n; ++i){
            mp[arr[i]]++;
        }
        for(auto it:mp){
            v.push_back(it.second);
        }
        sort(v.begin(), v.end());
        int m = v.size();
        for(int i=0; i<v.size(); ++i){
            if(v[i]<=k) {
                m--;
                k -= v[i];
            }
        }
        return m;
    }
};