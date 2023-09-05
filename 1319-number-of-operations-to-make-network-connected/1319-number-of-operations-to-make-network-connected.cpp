class Solution {
    
public:

    int par[100001];
    int siz[100001];
     
     void init(int n){
         for(int i=0; i<n; ++i)
         par[i] = i, siz[i] = 1;
     }
     int findP(int a){
         if(par[a] == a) return a;
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

    int makeConnected(int n, vector<vector<int>>& edges) {
        init(n);

        int extra = 0;

        for(auto it:edges){
             int a = it[0];
             int b = it[1];

             if(findP(a) == findP(b)) extra++;

             else{
                 merge(a,b);
             }
        }
        int cmp = 0;
        for(int i=0; i<n; ++i){
            if(par[i]==i) cmp++;
        }
        int ans = cmp-1;
        if(extra>=ans) return ans;
        return -1;
    }
};