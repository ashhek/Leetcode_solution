class Solution {
public:
    int minOperations(vector<string>& logs) {
        int cnt = 0;

        for(string& s : logs){
            if(s== "./") continue;
            if(s=="../"){
                if(cnt==0) cnt = 0;
                else cnt--;
            }
            else cnt++;
        }
        return cnt;
    }
};