// prob: https://neetcode.io/problems/products-of-array-discluding-self/question?list=blind75


// core idea: compute whole prod leaving 0s and divide each elemnt with the prod 
// if one 0 --> that zero pos gets prod
// if more than one zer: all arr becomes zero
// no zeroes: each output element: prod/nums[i]

// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zeroCount = 0;
        long long prod = 1;   // use long long to reduce overflow risk
        
        // First pass: count zeros and compute product of non-zero elements
        for (int n : nums) {
            if (n == 0) {
                zeroCount++;
            } else {
                prod *= n;
            }
        }

        vector<int> res;
        for (int n : nums) {
            if (zeroCount > 1) {
                // More than one zero → everything is zero
                res.push_back(0);
            }
            else if (zeroCount == 1) {
                // Exactly one zero
                if (n == 0)
                    res.push_back(prod);  // only zero position gets product
                else
                    res.push_back(0);
            }
            else {
                // No zeros → safe to divide
                res.push_back(prod / n);
            }
        }
        return res;
    }
};

// edge case more than one xero --> caused probs

// class Solution {
// public:
//     vector<int> productExceptSelf(vector<int>& nums) {
//         int prod = 1;
//         for (int n:nums)
//             prod *= n;
//         vector<int> res;
//         for (int n: nums) {
//             if (n==0)
//                 res.push_back(prod);
//             else 
//                 res.push_back(prod/n);
//         }
//         return res;
//     }
// };

