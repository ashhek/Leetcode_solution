class Solution {
public:
    bool judgeSquareSum(int c) {
        long low = 0;
        long high = sqrt(c);
        

        while(low<=high){
            long target = (low*low) + (high*high);
            if(target==c)
            return true;

            else if(target>c){
                high--;
            }
            else{
                low++;
            }
        }
        return false;
    }
};