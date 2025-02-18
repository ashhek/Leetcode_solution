class Solution {
    bool backTrack(int idx, string& s, string& res, vector<int>& seen,
                   char prev) {
        if (res.size() == s.size()) {
            return true;
        }

        //cout << "idx: " << idx << ", res: " << res << endl;


        for (int i = 1; i <= 9; ++i) {
            if (!seen[i]) {
                if (prev == '#') {
                    seen[i] = 1;
                    res.push_back(i + '0');
                    if (backTrack(idx + 1, s, res, seen, s[idx]))
                        return true;
                    res.pop_back();
                    seen[i] = 0;
                }
                else if (prev == 'I') {
                    if (res.back() - '0' < i) {
                        res.push_back(i + '0');
                        seen[i] = 1;
                        if (backTrack(idx + 1, s, res, seen, s[idx]))
                            return true;
                        res.pop_back();
                        seen[i] = 0;
                    }
                }
                else if (prev == 'D') {
                    if (res.back() - '0' > i) {
                        res.push_back(i + '0');
                        seen[i] = 1;
                        if (backTrack(idx + 1, s, res, seen, s[idx]))
                            return true;
                        res.pop_back();
                        seen[i] = 0;
                    }
                }
            }
        }
        return false;
    }

public:
    string smallestNumber(string pattern) {
        pattern.push_back('D');
        string res;
        vector<int> seen(10, 0);
        backTrack(0, pattern, res, seen, '#');
        return res;
    }
};