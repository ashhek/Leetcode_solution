class Solution {
public:
    char repeatedCharacter(string s) {
        set<char>st;

        for(int i=0; i<s.size(); ++i){
            
            if(st.count(s[i])==1) return s[i];
            st.insert(s[i]);
        }
        return '0';
    }
};