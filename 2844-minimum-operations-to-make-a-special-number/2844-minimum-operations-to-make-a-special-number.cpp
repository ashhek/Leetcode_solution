class Solution {
public:
    int minimumOperations(string num) {

        int n = num.size();
        
        bool Zfound = 0, Onfound = 0;
        vector<int>v;

        for(int i=num.size()-1; i>=0; --i){
            if(Zfound and num[i]=='0') v.push_back(n-2-i);
            if(Zfound and num[i]=='5') v.push_back(n-2-i);
            if(Onfound and num[i]=='7') v.push_back(n-2-i);
            if(Onfound and num[i]=='2') v.push_back(n-2-i);
            if(num[i]=='0'){
                Zfound = 1;
            }
            if(num[i]=='5'){
                Onfound = 1;
            }
        }
        if(v.size()==0 and Zfound) return num.size()-1;
        else if(v.size()==0) return num.size();
        sort(v.begin(), v.end());
        return v[0];

    }
};