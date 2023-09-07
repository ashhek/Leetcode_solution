class Solution {
public:
    int siz[1001], par[1001];
    void init(int n){
        for(int i=0; i<n; ++i)
        par[i]=i, siz[i]=1;
    }
    int findP(int a){
        if(par[a]==a) return a;
        return par[a] = findP(par[a]);
    }
    void merge(int a, int b){
        a = findP(a);
        b = findP(b);

        if(a==b) return;
        
        if(siz[a]<siz[b]) swap(a,b);

        par[b] = a;
        siz[a] += siz[b];
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        init(n);
        sort(accounts.begin(), accounts.end());
        unordered_map<string,int>m;

        for(int i=0; i<n; ++i){
            for(int j=1; j<accounts[i].size(); ++j){
                string name = accounts[i][j];
                if(m.find(name)==m.end()){
                    m[name] = i;
                }
                else{
                    merge(i, m[name]);
                }
            }
            
        }
         vector<string>mergedMail[n];
            for(auto it:m){
                string mail = it.first;
                int node = findP(it.second);
                mergedMail[node].push_back(mail);
            }
         vector<vector<string>>ans;
         for(int i=0; i<n; ++i){
             if(mergedMail[i].size()==0) continue;
             sort(mergedMail[i].begin(), mergedMail[i].end());
             vector<string>temp;
             temp.push_back(accounts[i][0]);
             for(auto it:mergedMail[i])
             temp.push_back(it);

             ans.push_back(temp);
         }   
         sort(ans.begin(), ans.end());
         return ans;
    }
};