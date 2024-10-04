class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        sort(skill.begin(), skill.end());

        long long ans = 0;
        int i = 0;
        int j = n-1;
        int target = accumulate(skill.begin(), skill.end(), 0LL) / (n/2);

        while(i < j) {
            if(skill[i] + skill[j] == target) {
                ans += (skill[i]*skill[j]);
            } else {
                return -1;
            }
            i++, j--;
        }
        return ans;
    }
};