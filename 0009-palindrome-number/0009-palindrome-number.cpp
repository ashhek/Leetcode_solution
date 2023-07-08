class Solution {
public:
    bool isPalindrome(int x) {
        vector<int>num;
        if(x<0) return false;
       while(x){
          num.push_back(x%10);
          x /= 10;
       }
       int n = num.size();
       int i=0, j=n-1;
       while(i<j){
           if(num[i] != num[j])
           return false;
           i++; j--;
       }
       return true;
    }
};