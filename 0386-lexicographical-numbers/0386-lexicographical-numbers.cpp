class Solution {
public:
    vector<int> res;
    void dfs(int ind, int n) {
        if (ind > n)
            return;

        res.push_back(ind);

        for (int i = 0; i < 10; ++i) {
            if (ind * 10 + i > n)
                return;
            dfs(ind * 10 + i, n);
        }
    }

    vector<int> lexicalOrder(int n) {

        for (int i = 1; i <= 9; ++i) {
            dfs(i, n);
        }
        return res;
    }
};