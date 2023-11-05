class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        
        int c = arr[0];
        int cnt = 0;
        for(int i=1; i<arr.size(); ++i){
           if(arr[i]>c) c = arr[i], cnt = 0;
           if(++cnt == k) break;
        }
        return c;
    }
};