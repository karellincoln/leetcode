class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
    }

    void push(int x) {
        st.push(x);
        if (min.empty()) min.push(x);
        else {
            int a = min.top();
            if(x < a) min.push(x);
            else min.push(a);
        }
    }

    void pop() {
        st.pop();
        min.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return min.top();
    }

    stack<int> st;
    stack<int> min;
};