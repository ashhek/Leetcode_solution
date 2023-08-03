class Solution {
public:
    string sortVowels(string s) {
        int n = s.size();
        priority_queue<int, vector<int>, greater<int>>minh;

        for(int i=0; i<n; ++i){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i] == 'o' || s[i] == 'u' || s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U'){
                minh.push(s[i]);
            }
        }
        for(int i=0; i<n; ++i){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i] == 'o' || s[i] == 'u' || s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U'){
                s[i] = minh.top();
                minh.pop();
            }
        }
        return s;
        
    }
};