class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        string t = s1;
        for(int i=0; i<2; ++i){
            if(t[i] != s1[i]){
                swap(t[i], t[i+2]);
            }     
        }
        if(t==s2) return true;
        
        for(int i=0; i<2; ++i){
            if(s2[i] != s1[i]){
                swap(s2[i], s2[i+2]);
            }     
        }
        if(s1==s2) return true;
        return false;
            
    }
};