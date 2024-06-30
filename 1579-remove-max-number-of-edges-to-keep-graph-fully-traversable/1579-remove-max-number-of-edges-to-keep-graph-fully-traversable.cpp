class dsu {
public:
    int par[100001];
    int siz[100001];
    int component;

    dsu(int n) {
        component = n;
        for (int i = 1; i <= n; ++i)
            par[i] = i, siz[i] = 1;
    }

    int findP(int x) {
        if (par[x] == x)
            return x;
        return par[x] = findP(par[x]);
    }

    void merge(int a, int b) {
        a = findP(a);
        b = findP(b);

        if (siz[b] > siz[a])
            swap(a, b);

        par[b] = a;
        siz[a] += siz[b];

        component--;
    }

    bool isConnected() { return component == 1; }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        dsu alice(n);
        dsu bob(n);

        auto lambda = [](vector<int>& a, vector<int>& b) {
            return a[0] > b[0];
        };

        sort(edges.begin(), edges.end(), lambda);
        int edge = 0;

        for (auto it : edges) {
            int type = it[0];
            int u = it[1];
            int v = it[2];
            bool ok = false;

            if (type == 3) {
                if (alice.findP(u) != alice.findP(v))
                    alice.merge(u, v), ok = true;

                if (bob.findP(u) != bob.findP(v))
                    bob.merge(u, v), ok = true;

                if (ok)
                    edge++;
            }
            if (type == 2) {
                if (bob.findP(u) != bob.findP(v))
                    bob.merge(u, v), edge++;
            }
            if (type == 1) {
                if (alice.findP(u) != alice.findP(v))
                    alice.merge(u, v), edge++;
            }
        }
        if (alice.isConnected() && bob.isConnected()) {
            return edges.size() - edge;
        }
        return -1;
    }
};