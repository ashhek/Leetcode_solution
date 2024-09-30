class CustomStack {
public:
    int ub;
    stack<int>st;
    CustomStack(int maxSize) {
        ub = maxSize;
    }
    
    void push(int x) {
        if(st.size() < ub) {
            st.push(x);
        }
    }
    
    int pop() {
        if(st.empty()) return -1;
        int ele = st.top();
        st.pop();
        return ele;
    }
    
    void increment(int k, int val) {
        stack<int>st2;
        while(!st.empty()) {
            int x = st.top();
            st2.push(x);
            st.pop();
        }
        while(k--) {
            if(st2.empty()) break;
            int x = st2.top()+val;
            st.push(x);
            st2.pop();
        }
        while(!st2.empty()) {
            int x = st2.top();
            st.push(x);
            st2.pop();
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */