class Solution {
public:
    #define MAXN 50000
    vector<int> H;
    int N, T[4 * MAXN];

    void Build(int lo, int hi, int v) {
        if (lo == hi) {
            T[v] = H[lo];
            return;
        }
        int mid = (lo + hi) / 2;
        Build(lo, mid, 2 * v + 1);
        Build(mid + 1, hi, 2 * v + 2);
        T[v] = max(T[2 * v + 1], T[2 * v + 2]);
    }

    int Query(int lo, int hi, int v, int x, int i) {
        if (lo == hi)
          return T[v] > x && lo >= i ? lo : -1;
        int mid = (lo + hi) / 2;
        if (T[2 * v + 1] > x && mid >= i) {
            int Q = Query(lo, mid, 2 * v + 1, x, i);
            if (Q != -1)
              return Q;
        }
        return Query(mid + 1, hi, 2 * v + 2, x, i);
    }

    vector<int> leftmostBuildingQueries(vector<int>& H1, vector<vector<int>>& Q) {
        N = H1.size(); H = H1;
        Build(0, N - 1, 0);
        vector<int> ans(Q.size());
        for (int i = 0; i < Q.size(); i++) {
            if (Q[i][0] > Q[i][1]) swap(Q[i][0], Q[i][1]);
            if (H[Q[i][1]] > H[Q[i][0]] || Q[i][1] == Q[i][0])
              ans[i] = Q[i][1];
            else 
              ans[i] = Query(0, N - 1, 0, H[Q[i][0]], Q[i][1]);
        }
        return ans;
    }
};