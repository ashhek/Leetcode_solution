class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        
        for(int i=1; i<words.size(); i++)
        {
            string s1 = words[i];
            string s2 = words[i-1];
            sort(s1.begin(), s1.end());
            sort(s2.begin(), s2.end());
            if(s1 == s2)
            {
                words.erase(words.begin() + i);
                i--;
            }
            
        }
        return words;
    }
    
};