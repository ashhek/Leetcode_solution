class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int maxFruit = 0;
        int left = 0;
        int sum = 0;
        map<int,int>mp;

        for(int right = 0; right < fruits.size(); ++right) {
            sum++;
            mp[fruits[right]]++;

            while(mp.size() > 2) {
                mp[fruits[left]]--;
                if(mp[fruits[left]] == 0) mp.erase(fruits[left]);
                sum--;
                left++;
            }
            maxFruit = max(maxFruit, sum);
        }
        return maxFruit;
    }
};