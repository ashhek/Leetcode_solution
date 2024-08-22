class Solution {
public:
    int findComplement(int num) {
        // method-1
        //int n = (int)log2(num) + 1;

        // for (int i = 0; i < n; ++i) {
        //     num ^= (1 << i);
        // }
       // return num;
        // method - 2

         //int n = (int)log2(num) + 1;
        // unsigned mask = (1U<<n) - 1;
        // return mask ^ num;

        //method-3
        int i = 0;
        int complement = 0;

        while(num) {
            if(!(num & 1)) {
                complement |= (1<<i);
            }
            num >>= 1;
            i++;
        } 
        return complement;
    }
};