class Solution {
public:
    int countSeniors(vector<string>& details) {
        int n = details.size();
        int cnt = 0;

        for(string& s: details){
            string age = s.substr(11, 2);
            int x = stoi(age);
            if(x>60) cnt++;
        }
        return cnt;
    }
};