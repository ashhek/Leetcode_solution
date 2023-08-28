class Solution {
public:
    bool isFascinating(int n) {
        unordered_set<int> m;
        int t=0;
        for (int i=1;i<4;i++){
            t = n*i;
            while (t>0) {
                if (t%10==0 || m.find(t%10)!=m.end()) return false;
                m.insert(t%10);
                t /=10;
            }
        }
        return true;
    }
};