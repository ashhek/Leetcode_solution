class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();

        int start = 0, end = n-1;
        int index = 0;
        while(start<=end){
            int mid = (end+start)/2;

            if(letters[mid]<target) start = mid+1;
            else if(letters[mid]>target){
                 end = mid-1;
                 index = mid;
            }
            else start = mid+1;
        }
        return letters[index] ;
    }
};