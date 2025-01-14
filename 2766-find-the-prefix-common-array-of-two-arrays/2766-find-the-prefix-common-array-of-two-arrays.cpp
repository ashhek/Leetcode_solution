class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> res;

        set<int>st;
        for (int i = 0; i < n; ++i) {
            st.insert(A[i]);
            st.insert(B[i]);
            res.push_back((i+1)*2 - st.size());
        }
        return res;
    }
};