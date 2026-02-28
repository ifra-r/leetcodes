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

// 2nd approach: only maintain min heap of k largest elements

// time complexity: O(n) + O(n log k) + O(k log k) = O(n log k) 
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;

        // count freq
        for (int i = 0; i < nums.size(); ++i) 
            freq[nums[i]]++;

        // maintain k largest in minHeap
        for (auto &p : freq) {    
            minHeap.push({p.second, p.first});

            if (minHeap.size() > k) 
                minHeap.pop();
        }
        
        vector<int> res;
        while (!minHeap.empty()) {
            res.push_back(minHeap.top().second);
            minHeap.pop();
        }

        return res;
    }
};


// 3rd approach: Bucket sort
// time complexity:  O(n)+O(m)+O(n) = O(n)
// spac ecomplexity:  O(n)

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;    // max possible freq = n 
        //Count freq
        for (auto x : nums)
            freq[x]++;

        // 2D Buckets
        vector<vector<int>> bucket(nums.size() + 1);
        for (auto &p : freq)
            bucket[p.second].push_back(p.first);     // freq --> list of nums w that freq

        vector<int> res;
        // start from high freq and collect k freqs
        for (int i = nums.size(); i >= 0 && res.size() < k; --i) {
            // iterate in list of each freq starting from high to low till k
            for (auto x : bucket[i]) {
                res.push_back(x);
                if (res.size() == k) break;
            }
        }

        return res;
    }
};

