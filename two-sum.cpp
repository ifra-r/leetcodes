class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for (int i=0; i<nums.size(); ++i) {
            int val = nums[i];

            if (map.find(target-val) != map.end())
                return {i, map[target-val]};
            map[val] = i;   // add value
        }
        return {};
    }
};


// 2 ptr approach with (value, index pair)

class Solution1 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // make (value, index) pair and sort
        // sort --> to use 2 ptr approach
        // (value, index) --> to keep track of index as it will be lost after sorting
        vector<pair<int,int>> v;
        for (int i = 0; i < nums.size(); i++)
            v.push_back({nums[i], i});   // {value, index}

        sort(v.begin(), v.end());

        int left = 0, right = v.size()-1;
        while (left < right) {
            int sum = v[left].first + v[right].first;
            if (sum == target) return {v[left].second, v[right].second};
            if (sum > target)
                right--;    // make sum smaller, move to smaller elements
            else
                left++;     // make sum larger next time
        }
        return {};
    }
};


// Naive approach
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       for (int i=0; i<nums.size(); i++) {
        for (int j=0; j<nums.size(); j++) {
            if (i==j) continue;
            int sum = nums[i] + nums[j];
            if (sum==target)
                return {i,j};
        }
       } 
       return {};
    }
};