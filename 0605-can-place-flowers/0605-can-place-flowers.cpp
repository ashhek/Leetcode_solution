class Solution {
public:
    bool canPlaceFlowers(vector<int>& bed, int n) {
        bed.insert(bed.begin(), 0);
        bed.push_back(0);

        int m = bed.size();

        for(int i=1; i<m-1; ++i){
            if(bed[i-1]+bed[i]+bed[i+1] == 0){
                n--;
                i++;
            }
        }
        return n<=0;
    }
};