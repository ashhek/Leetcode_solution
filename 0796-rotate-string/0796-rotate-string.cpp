class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size()!=goal.size()) return 0;
        string t = s+s;
        int found = t.find(goal);
        if(found != string::npos){
            return 1;
        }
        return 0;
    }
};