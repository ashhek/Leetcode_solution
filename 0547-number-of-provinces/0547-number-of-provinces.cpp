class Solution {

    int par[100001];
    //int siz[100001];

    void init(int n){
        for(int i=0; i<n; ++i)
        par[i] = i;
    }
    
    int findP(int n){
        if(par[n] == n) return n;
        return par[n] = findP(par[n]);
    }

    void mearge(int a, int b){
        a = findP(a);
        b = findP(b);

        //if(siz[a]<siz[b]) swap(a,b);

        par[b] = a;
        //siz[a] += siz[b];
    }


public:
    int findCircleNum(vector<vector<int>>& matrix) {

        int n = matrix.size();

        init(n);

        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){

                if(matrix[i][j]){
                    mearge(i,j);                        
                }

            }
        }

        int ans = 0;
        
        for(int i=0; i<n; ++i){
            if(i==par[i]) ans++;
        }
        return ans;
      
    }
};