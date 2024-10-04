class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        long long n = skill.size();
        long long totalSum = accumulate(skill.begin(), skill.end(), 0LL);
        long long pairSum = totalSum / (n / 2);
        long long res = 0;
      
        multimap<int, long long> mp;
        for (int i : skill) {
            mp.insert({i, -1});
        }

       
        while (!mp.empty()) {
           
            auto it = mp.begin();
            int a = it->first;
            mp.erase(it);  

            int b = pairSum - a;

            auto pairIt = mp.find(b);
            if (pairIt == mp.end()) {
                return -1;  
            }
            mp.erase(pairIt);

            res += (a * b);
        }

        return res;
    }
};
