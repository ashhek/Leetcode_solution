class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        //sort(arr.begin(), arr.end());
        unordered_set<int>s;
        int count = 0;
        for(int i=0; i<arr.size(); ++i){
            if(arr[i]==0) count++;
            s.insert(arr[i]);
        }

        if(count>1) return true;
        
        for(int i=0; i<arr.size(); ++i){  
            if(arr[i]==0) continue;   
            if(s.count(2*arr[i])) return true;
        }
        return false;
    }
};