class Solution {
public:
    int passThePillow(int n, int time) {
        int dir = 1;
        int i = 1;
        while(time--){
            i += dir;
            if(i==n)
                dir = -1;
            if(i==1){
                dir = 1;
            }    
        
        }
        return i;
    }
};