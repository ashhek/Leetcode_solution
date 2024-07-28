class DSU{
vector<int>parent,sizee;
public:
    DSU(int n){
        parent.resize(n+1);
        sizee.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
            sizee[i]=1;
        }
    }
    int findP(int x){
        if(x==parent[x]) return x;
        return parent[x]=findP(parent[x]);
    }
    void merge(int a,int b){
        int up_a = findP(a);
        int up_b = findP(b);
        if(up_a==up_b) return;
        else if(sizee[up_a]>sizee[up_b]){
            sizee[up_a]+=sizee[up_b];
            parent[up_b] = up_a;
        }
        else{
            sizee[up_b]+=sizee[up_a];
            parent[up_a] = up_b;
        }
    }
};
class Solution {
public:
    bool canReachCorner(int X, int Y, vector<vector<int>>& circles) {
        int n = circles.size();
        DSU ds(n+2);
        for(int i=0;i<n;i++){
            long long int x = circles[i][0];
            long long int y = circles[i][1];
            long long int r = circles[i][2];
            if(x-r<=0 or y+r>=Y) ds.merge(n,i);
            if(x+r>=X or y-r<=0) ds.merge(n+1,i);
            
            for(int j=0;j<i;j++){
                long long int x1 = circles[j][0];
                long long int y1 = circles[j][1];
                long long int r1 = circles[j][2];
                if((x1-x)*(x1-x) + (y1-y)*(y1-y) <= (r1+r)*(r1+r)) ds.merge(i,j);
            }
        }
        return ds.findP(n)!=ds.findP(n+1);
    }
};