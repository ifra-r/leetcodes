class Solution {
public:
    bool is_number(char c) {
        if (c >= '0' && c<='9')
            return true;
        return false;
    }
    string encode(vector<string>& strs) {
        string encoded = "";
        for (string s: strs) {
            int len = s.length();
            encoded += to_string(len) + '#' + s;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> strs;
        for (int i=0; i<s.length(); ++i) {
            // if num appears ==> compute length
            int num = 0;
            while (i < s.length() && is_number(s[i])) {
                num = num * 10 + (s[i] - '0');
                i++;
            }
            // generate string of length "num"
            string candidate = "";
            for (int j=0; j<num; ++j) {
                candidate += s[++i];   // pre-inc to skip separator // outerloop index
            }
            strs.push_back(candidate);
        }
        return strs;
    }
};

// complexity
// Operation    Time	Space
// Encode	    O(S)	O(S)
// Decode	    O(S)	O(S)