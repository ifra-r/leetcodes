// prob link: https://neetcode.io/problems/top-k-elements-in-list/question

// first approach

// time complexity: O(nlogn)
// spac ecomplexity: O(n)
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        priority_queue<pair<int,int>> maxHeap;  // must store pair

        for (int i = 0; i < nums.size(); ++i) {
            freq[nums[i]]++;
        }

        for (auto &p : freq) {   // can't index unordered_map with i
            maxHeap.push({p.second, p.first});
        }

        vector<int> res;

        for (int i = 0; i < k; ++i) {
            res.push_back(maxHeap.top().second);  // pop() returns void
            maxHeap.pop();
        }

        return res;
    }
};

