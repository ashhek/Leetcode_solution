class Solution {
private: 
    bool helper(int num){
        string s = to_string(num);
        int n = s.size();
        if(n%2) return 0;
        
        int leftSum = 0;
        int rightSum = 0;

        for(int i=0; i<n/2; ++i){
            leftSum += s[i] - '0';
            rightSum += s[n-i-1] - '0';
        }
        return leftSum==rightSum;
    }    
public:
    int countSymmetricIntegers(int low, int high) {
        int ans = 0;
        for(int i=low; i<=high; ++i){
            if(helper(i)) ans++;
        }
        return ans;
    }
};