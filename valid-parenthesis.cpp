// prob: https://neetcode.io/problems/validate-parentheses/question

class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        for (char c:s) {
            // opening brackets
            if (c=='(' || c=='{' || c=='[')
                st.push(c);
            //closing brackets
            else {
                if (st.empty()) 
                    return false;
                // top mismatch cases
                char top = st.top();
                st.pop();
                if ((c == ')' && top != '(') ||
                    (c == '}' && top != '{') ||
                    (c == ']' && top != '['))
                    return false;
            }
        }
        return st.empty();
    }
};

// complexity
// time : O(n)