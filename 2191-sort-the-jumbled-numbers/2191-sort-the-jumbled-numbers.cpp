class Solution {
#define ll long long
    // static bool comparator(const std::pair<int, int>& a,
    //                       const std::pair<int, int>& b) {
    //     if (a.first == b.first) {
    //         return a.second < b.second;
    //     }
    //     return a.first < b.first;
    // }

public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n = mapping.size();
        vector<ll> mp(n);

        for (int i = 0; i < n; ++i)
            mp[i] = mapping[i];

        vector<ll> v;
        for (int i : nums) {
            string s = to_string(i);
            string t;

            for (int j : s) {
                int ind = j - '0';
                char ch = mp[ind] + '0';
                t += ch;
            }

            int x = stoi(t);
            v.push_back(x);
        }

        vector<pair<ll, ll>> p;
        for (int i = 0; i < nums.size(); ++i) {
            p.push_back({v[i], nums[i]});
        }
        stable_sort(p.begin(), p.end(), [&](const pair<int, int>& a, const pair<int, int>& b) {
        return a.first < b.first; 
    });
        vector<int> res;
        for (auto pair : p) {
            res.push_back((int)pair.second);
        }
        return res;
    }
};