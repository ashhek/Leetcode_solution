class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        vector<pair<int, char>> v = {{a, 'a'}, {b, 'b'}, {c, 'c'}};
        string s;

        while (true) {
            // Sort the vector by the remaining counts (largest first)
            sort(v.rbegin(), v.rend());

            bool added = false;

            // Try to add the first character (with the largest count)
            if (v[0].first > 0) {
                int len = s.size();
                // Check if the last two characters are the same as the current character
                if (len >= 2 && s[len - 1] == v[0].second && s[len - 2] == v[0].second) {
                    // If the first character cannot be added, try adding the second character
                    if (v[1].first > 0) {
                        s += v[1].second;
                        v[1].first--;
                        added = true;
                    }
                } else {
                    // Add the character with the largest count
                    s += v[0].second;
                    v[0].first--;
                    added = true;
                }
            }

            // If no character could be added, break the loop
            if (!added) {
                break;
            }
        }

        return s;
    }
};
