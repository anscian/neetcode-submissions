class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (auto &c : s) {
            switch (c) {
            case ')':
                if (st.empty() || st.top() != '(')
                    return false;
                st.pop(); break;
            case ']':
                if (st.empty() || st.top() != '[')
                    return false;
                st.pop(); break;
            case '}':
                if (st.empty() || st.top() != '{')
                    return false;
                st.pop(); break;

            case '(': case '[': case '{':
                st.push(c);
            default:
            }
        }

        return st.empty();
    }
};
