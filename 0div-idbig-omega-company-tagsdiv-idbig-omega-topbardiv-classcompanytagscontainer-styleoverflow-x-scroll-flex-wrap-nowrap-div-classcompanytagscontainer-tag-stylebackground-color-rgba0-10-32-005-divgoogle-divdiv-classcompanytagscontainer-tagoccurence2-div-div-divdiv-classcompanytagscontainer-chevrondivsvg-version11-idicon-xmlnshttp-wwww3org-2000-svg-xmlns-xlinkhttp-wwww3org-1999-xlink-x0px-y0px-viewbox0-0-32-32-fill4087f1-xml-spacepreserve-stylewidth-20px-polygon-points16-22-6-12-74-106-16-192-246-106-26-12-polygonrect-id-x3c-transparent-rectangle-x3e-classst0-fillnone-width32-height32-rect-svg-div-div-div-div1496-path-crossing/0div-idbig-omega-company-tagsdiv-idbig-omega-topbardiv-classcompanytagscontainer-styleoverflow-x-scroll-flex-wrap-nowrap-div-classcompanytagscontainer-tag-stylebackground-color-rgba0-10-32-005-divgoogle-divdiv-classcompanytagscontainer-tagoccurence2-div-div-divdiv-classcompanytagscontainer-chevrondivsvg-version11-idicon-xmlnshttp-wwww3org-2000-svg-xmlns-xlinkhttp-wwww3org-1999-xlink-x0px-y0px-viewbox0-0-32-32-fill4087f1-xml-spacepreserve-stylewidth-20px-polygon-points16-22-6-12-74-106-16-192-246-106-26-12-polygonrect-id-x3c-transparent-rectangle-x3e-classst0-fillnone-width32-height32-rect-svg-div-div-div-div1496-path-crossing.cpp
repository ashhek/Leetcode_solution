class Solution {
public:
    bool isPathCrossing(string path) {
        set<pair<int,int>>st;
        int x = 0, y = 0;
        st.insert({0, 0});
        for(int i=0; i<path.size(); ++i){
            if(path[i]=='N') y++;
            if(path[i]=='E') x++;
            if(path[i]=='S') y--;
            if(path[i]=='W') x--;

            if(st.count({x,y})>0) return true;
              st.insert({x,y});
        }
        return false;

    }
};