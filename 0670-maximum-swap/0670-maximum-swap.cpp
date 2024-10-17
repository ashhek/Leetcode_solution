class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int n = s.size();

        vector<int> maxIndex(n);
        maxIndex[n - 1] = n - 1;

        for (int i = n - 2; i >= 0; --i) {
            if (s[i] > s[maxIndex[i + 1]]) {
                maxIndex[i] = i;
            } else {
                maxIndex[i] = maxIndex[i + 1];
            }
        }

        for (int i = 0; i < n; ++i) {
            if (s[i] != s[maxIndex[i]]) {
                swap(s[i], s[maxIndex[i]]);
                break;
            }
        }

        return stoi(s);
    }
};
