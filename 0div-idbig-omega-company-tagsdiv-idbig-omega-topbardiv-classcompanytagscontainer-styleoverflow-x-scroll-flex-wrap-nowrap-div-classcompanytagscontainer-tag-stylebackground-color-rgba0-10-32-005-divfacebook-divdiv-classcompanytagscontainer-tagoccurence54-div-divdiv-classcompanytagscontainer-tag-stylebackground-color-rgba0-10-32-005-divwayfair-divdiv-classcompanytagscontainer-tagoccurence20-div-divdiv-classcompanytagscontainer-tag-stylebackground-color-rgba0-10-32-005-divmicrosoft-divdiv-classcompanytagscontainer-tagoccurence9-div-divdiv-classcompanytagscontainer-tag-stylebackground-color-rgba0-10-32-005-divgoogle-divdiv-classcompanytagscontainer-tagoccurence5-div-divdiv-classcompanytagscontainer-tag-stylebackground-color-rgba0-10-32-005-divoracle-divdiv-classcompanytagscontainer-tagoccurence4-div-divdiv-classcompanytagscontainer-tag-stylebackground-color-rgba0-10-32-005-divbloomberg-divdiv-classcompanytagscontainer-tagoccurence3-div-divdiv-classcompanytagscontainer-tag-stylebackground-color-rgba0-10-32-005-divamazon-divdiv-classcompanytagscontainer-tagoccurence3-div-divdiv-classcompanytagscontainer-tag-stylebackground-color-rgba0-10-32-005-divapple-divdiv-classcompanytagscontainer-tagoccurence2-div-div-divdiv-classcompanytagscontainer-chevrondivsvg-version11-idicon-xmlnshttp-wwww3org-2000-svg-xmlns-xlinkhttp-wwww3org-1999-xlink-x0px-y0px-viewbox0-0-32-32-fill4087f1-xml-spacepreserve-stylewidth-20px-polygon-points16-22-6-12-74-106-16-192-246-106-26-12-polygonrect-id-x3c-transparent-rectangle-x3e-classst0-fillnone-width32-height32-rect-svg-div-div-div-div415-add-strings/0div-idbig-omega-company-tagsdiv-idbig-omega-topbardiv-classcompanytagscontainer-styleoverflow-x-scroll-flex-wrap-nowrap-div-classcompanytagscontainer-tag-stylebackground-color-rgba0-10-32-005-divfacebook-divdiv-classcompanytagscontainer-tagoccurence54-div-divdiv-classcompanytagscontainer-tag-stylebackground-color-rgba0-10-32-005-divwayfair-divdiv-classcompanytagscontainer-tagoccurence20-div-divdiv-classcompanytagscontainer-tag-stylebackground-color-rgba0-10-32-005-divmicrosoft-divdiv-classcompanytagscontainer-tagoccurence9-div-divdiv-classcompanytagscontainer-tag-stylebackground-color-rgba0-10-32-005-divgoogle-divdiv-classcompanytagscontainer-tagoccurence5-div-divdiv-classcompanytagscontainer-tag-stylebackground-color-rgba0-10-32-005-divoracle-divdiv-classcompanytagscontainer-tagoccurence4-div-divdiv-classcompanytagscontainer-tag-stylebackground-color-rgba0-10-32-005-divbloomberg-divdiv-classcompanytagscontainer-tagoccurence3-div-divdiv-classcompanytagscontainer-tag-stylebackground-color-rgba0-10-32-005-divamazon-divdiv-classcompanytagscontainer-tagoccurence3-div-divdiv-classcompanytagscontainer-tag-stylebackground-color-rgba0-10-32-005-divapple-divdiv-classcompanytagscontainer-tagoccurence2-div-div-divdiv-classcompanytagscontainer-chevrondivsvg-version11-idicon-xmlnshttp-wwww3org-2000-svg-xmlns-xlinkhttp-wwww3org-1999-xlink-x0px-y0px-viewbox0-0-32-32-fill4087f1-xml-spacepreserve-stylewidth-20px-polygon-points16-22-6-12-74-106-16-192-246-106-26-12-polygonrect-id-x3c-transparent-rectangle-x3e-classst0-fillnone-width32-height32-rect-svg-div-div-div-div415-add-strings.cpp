class Solution {
public:
    string addStrings(string num1, string num2) {
        
      
      int i = num1.size()-1;
      int j = num2.size()-1;
      
      string ans = "";
      long long int carry = 0;
      
      while(i>=0 || j>=0 || carry){
          long long int sum = 0;
          if(i>=0)
          sum += (num1[i--] - '0');
          if(j>=0)
          sum += (num2[j--] - '0');


          sum += carry;
          carry = sum/10;
          sum = sum%10;

          ans += to_string(sum);      
      }
      reverse(ans.begin(), ans.end());
      return ans;
    }
};