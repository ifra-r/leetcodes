// https://neetcode.io/problems/is-palindrome/question


// complexity:
// time: O(n)
// space: O(1)

class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0, end = s.size() - 1;

        while (start < end) {

            // skip no alphabetic chars from left and right
            while (start < end && !isalnum(s[start]))
                start++;
            while (start < end && !isalnum(s[end]))
                end--;
                
            // compare
            if (tolower(s[start]) != tolower(s[end]))
                return false;
            start++;
            end--;
        }
        return true;
    }
};
