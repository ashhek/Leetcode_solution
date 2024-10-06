class Solution {
public:
    static bool comp(string a,string b){
        if(a+b>b+a)return true;
        else return false;
    }
    int maxGoodNumber(vector<int>& nums) {
        vector<string>ans;
        for(int i=0;i<nums.size();i++){
            string temp="";
            if(nums[i]==0){
                    temp="0";
            }
            else while(nums[i]){
                 
                temp=to_string(nums[i]%2)+temp;
                nums[i]/=2;
            }

            ans.push_back(temp);
        }
        sort(ans.begin(),ans.end(),comp);
        string all=ans[0]+ans[1]+ans[2];
        int res=0,po=1;
        for(int i=all.size()-1;i>=0;i--){
            if(all[i]=='1')res+=po;
            po*=2;
        }
        return res;
        
        
        
    }
};