class Solution {
public:
    bool isArraySpecial(vector<int>& arr) {
        int n = arr.size();
        if(arr[0]%2==0){
            for(int i=1; i<n; ++i){
                if(i%2){
                    if(arr[i]%2 == 0)
                        return false;
                }
                else{
                    if(arr[i]%2)
                        return false;
                }
            }
        }
        else{
             for(int i=1; i<n; ++i){
                if(i%2){
                    if(arr[i]%2)
                        return false;
                }
                else{
                    if(arr[i]%2==0)
                        return false;
                }
            }
        }
        return true;
    }
};