// 3. Longest Substring Without Repeating Characters

class Solution(object):
    def lengthOfLongestSubstring(self, s): 
        char_index = {}
        start = 0
        max_len = 0

        for end in range(len(s)):
            ch = s[end]

            if ch in char_index and char_index[ch] >= start:
                start = char_index[ch] + 1  # move start to the right of last duplicate

            char_index[ch] = end   # add curr elemnt in dictionary
            max_len = max(max_len, end - start + 1)

        return max_len