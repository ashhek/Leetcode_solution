#include <vector>

class Solution {
public:
    int numTeams(std::vector<int>& rating) {
        int n = rating.size();
        if (n < 3) return 0;  // Not enough soldiers to form a team

        std::vector<int> dp_inc(n, 0), dp_dec(n, 0);
        int count = 0;

        for (int j = 0; j < n; ++j) {
            for (int i = 0; i < j; ++i) {
                if (rating[i] < rating[j]) {
                    dp_inc[j] += 1;
                    count += dp_inc[i];  // Count teams with this as the middle soldier
                }
                if (rating[i] > rating[j]) {
                    dp_dec[j] += 1;
                    count += dp_dec[i];  // Count teams with this as the middle soldier
                }
            }
        }

        return count;
    }
};
