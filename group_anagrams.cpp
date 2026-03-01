class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map <string, vector<string>> mp;

        // count freq of each str and convert it into a key (same freq--? same key, easy to group)
        for (string s: strs) {

            // freq map for curr str
            unordered_map <char, int> freq;
            for (char c: s)
                freq[c]++;

            // make key w freq map
            string key = "";
            for (char c = 'a'; c <='z'; c++) {
                key += ((freq[c] - 'a') + '#'); // # is separator
            }
            // push str with key ==> all str w same keys will be together.
            mp[key].push_back(s);
        }

        vector<vector<string>> res;
        for (auto &p: mp) {
            res.push_back(p.second);
        }
        return res;
    }
};

// n → number of strings
// k → maximum string length

// time complexoty: O(n∗k)
// space complexoty: O(n∗k)


// 2nd approach

// make constant lookup
// Improvement: replaced unordered_map<char,int> with fixed int freq[26] array
    // - Faster access and less memory overhead 
    
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map <string, vector<string>> mp;

        // count freq of each str and convert it into a key (same freq--? same key, easy to group)
        for (string s: strs) {

            // freq map for curr str
            int freq[26] = {0};
            for (char c: s)
                freq[c-'a']++;

            // make key w freq map
            string key = "";
            for (char c = 'a'; c <='z'; c++) 
                key += (to_string(freq[c-'a']) + '#'); // # is separator

            // push str with key ==> all str w same keys will be together.
            mp[key].push_back(s);
        }

        // group strs with same key
        vector<vector<string>> res;
        for (auto &p: mp) 
            res.push_back(p.second);
        return res;
    }
};

// time complexoty: O(n∗k)
// space complexoty: O(n∗k)



