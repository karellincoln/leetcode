class Solution {
public:
    void add(stack<int> &st) {
        int a = st.top();
        st.pop();
        int b = st.top();
        st.pop();

        st.push(a + b);
    }
    void sub(stack<int> &st) {
        int a = st.top();
        st.pop();
        int b = st.top();
        st.pop();

        st.push(b - a);
    }
    void mul(stack<int> &st) {
        int a = st.top();
        st.pop();
        int b = st.top();
        st.pop();

        st.push(a * b);
    }
    void div(stack<int> &st) {
        int a = st.top();
        st.pop();
        int b = st.top();
        st.pop();

        st.push(b / a);
    }
    void push(stack<int> &st, string token) {
        int result = 0;
        if(token[0] == '-'){
            for(int i = 1; i < token.size(); ++i) {
                result = result * 10 + token[i] - '0';
            }

            result = -result;
        }
        else {
            for(int i = 0; i < token.size(); ++i) {
                result = result * 10 + token[i] - '0';
            }
        }

        st.push(result);
    }

    int evalRPN(vector<string>& tokens) {
        if (tokens.size() == 0) return -1;

        stack<int> st;

        for (int i = 0; i < tokens.size(); ++i){
            if (tokens[i].size() == 1) {
                switch (tokens[i][0]) {
                    case '+':
                        add(st);
                        break;
                    case '-':
                        sub(st);
                        break;
                    case '*':
                        mul(st);
                        break;
                    case '/':
                        div(st);
                        break;
                    default :
                        push(st, tokens[i]);
                        break;
                }
            }
            else push(st, tokens[i]);
        }

        return st.top();
    }
};