class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int>leftMin(n, -1);
        vector<int>rightMin(n, n);

        stack<int>st;
        for(int i=0; i<n; ++i) {
            while(!st.empty() && heights[st.top()] > heights[i]) {
                rightMin[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        stack<int>st1;
        for(int i=n-1; i>=0; --i) {
            while(!st1.empty() && heights[st1.top()] > heights[i]) {
                leftMin[st1.top()] = i;
                st1.pop();
            }
            st1.push(i);
        }
        int res = 0;
        for(int i=0; i<n; ++i) {
            res = max(res, (rightMin[i] - leftMin[i]-1) * heights[i]);
        }
        return res;
    }
};
