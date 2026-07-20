
// approach 2; a better one
class Solution {
public:  
    // time complexity : O(n^2 log n)
    // space complexity: O(log n)
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());     // sort so we can use 2 ptr approach  
        set<vector<int>> s;     // set to avoid duplicates

        // for each element
        for (int i=0; i<nums.size(); ++i) {
            // init left and right for a 2 ptr approach
            int left = i+1, right = nums.size()-1;
            int target = -nums[i];
            while (left < right) {
                int sum = nums[left] + nums[right];
                if (sum < target)   // make sum bigger by moving to bigger elements in arr. cause its sorted
                    left++;
                if (sum > target)   // make sum smaller by taking advantage of sorting
                    right--;
                if (sum == target) {   
                    vector<int> temp = {nums[i], nums[left], nums[right]};
                    sort(temp.begin(), temp.end());
                    s.insert(temp);
                    left++, right--; // to avoid loop & ALSO keep going for other possible pairs in iteration
                }
            }
        }
        // convert to vector and return
        vector<vector<int>> res(s.begin(), s.end());
        return res;
    } 
};
// time complexxity break down of this approach
    // sort : n log n
    // outer loop : n 
    // inner loop : n (max n possible moves for pointers)
    // insert vector in set: log m



// Naive approach 1;

class Solution0 {
public:  
    // time complexity : O(n^3 log n)
    // space complexity: O(n^3)
    vector<vector<int>> threeSum(vector<int>& nums) {  
        set<vector<int>> s;     // set to avoid duplicates
        // iterate as pair indexed as x, x+1, x+2 to avoid same pair in different orderings
        for (int i=0; i<nums.size(); ++i) {
            for (int j=i+1; j<nums.size(); ++j) {
                for (int k=j+1; k<nums.size(); ++k){
                    int sum = nums[i] + nums[j] + nums[k];
                    if (sum==0) {
                        // 2 different indexes can have same value hence 2 diff pairs generated if 3sum=0. So, to eliminate that, sort res pair so we can check uniqueness each time before pushing
                        vector<int> temp = {nums[i], nums[j], nums[k]};
                        sort(temp.begin(),temp.end());
                        s.insert(temp);
                    }
                }
            }
        }
        // convert to vector and return
        vector<vector<int>> res(s.begin(), s.end());
        return res;
    } 
};

