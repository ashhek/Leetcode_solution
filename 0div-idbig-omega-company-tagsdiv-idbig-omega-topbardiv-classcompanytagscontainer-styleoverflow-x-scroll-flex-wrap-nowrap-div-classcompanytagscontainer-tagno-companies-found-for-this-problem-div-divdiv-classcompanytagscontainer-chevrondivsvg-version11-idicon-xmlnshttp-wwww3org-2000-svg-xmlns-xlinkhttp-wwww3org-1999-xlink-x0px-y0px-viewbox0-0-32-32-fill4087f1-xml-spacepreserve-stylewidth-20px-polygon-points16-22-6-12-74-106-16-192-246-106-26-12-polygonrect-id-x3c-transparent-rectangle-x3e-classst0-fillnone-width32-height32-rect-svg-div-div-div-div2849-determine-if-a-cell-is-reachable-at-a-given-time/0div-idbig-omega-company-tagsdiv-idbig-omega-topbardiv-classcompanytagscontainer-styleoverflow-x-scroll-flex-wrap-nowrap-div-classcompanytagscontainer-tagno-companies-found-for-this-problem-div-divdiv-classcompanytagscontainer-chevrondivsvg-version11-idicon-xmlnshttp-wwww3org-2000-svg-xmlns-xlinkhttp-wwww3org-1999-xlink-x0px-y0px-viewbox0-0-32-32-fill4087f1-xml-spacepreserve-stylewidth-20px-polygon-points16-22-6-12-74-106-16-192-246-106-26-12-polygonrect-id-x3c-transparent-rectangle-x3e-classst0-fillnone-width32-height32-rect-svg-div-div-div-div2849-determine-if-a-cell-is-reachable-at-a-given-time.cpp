class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        if(sx == fx && sy==fy) {
            if(t==0) return true;
            if(t==1) return false;
            return true;
        }
        int mini=min(abs(fy-sy),abs(fx-sx));
        int maxi=max(abs(fx-sx)-mini,abs(fy-sy)-mini);
        return maxi+mini <=t ;
    }
};