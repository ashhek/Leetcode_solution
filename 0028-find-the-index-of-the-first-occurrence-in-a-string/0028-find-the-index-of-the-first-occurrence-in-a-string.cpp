class Solution {
public:
    int strStr(string haystack, string needle) {
        
        for(int i=0; i<haystack.size(); ++i){
            int j=i;
            int cnt = 0;
            int ptr = 0;
            
            while(haystack[j]==needle[ptr] and ptr<needle.size()){
                j++;
                cnt++;
                ptr++;
            }
            if(cnt==needle.size()) return i;
        }
        return -1;
    }
};