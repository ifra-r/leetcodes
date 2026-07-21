class Solution {
public:
    // 2 ptr approach
    // time complexity: O(n)
    // space complexity: O(1) 
    int maxArea(vector<int>& heights) {
        int max = 0;    
        int i=0, j=heights.size()-1;
        while (i<j) {
            int width = abs(i-j);   // check distance between 2 containers by subtracting their indexes and taking absolute so its always +ve
            int height = min(heights[i], heights[j]);   // min height is the max height till it can store water
            int vol = width * height;
            if (vol > max)  max = vol;
            if (heights[i] < heights[j])
                i++;    // advance i as you wont get more width with this height
            else
                j--;    // move j inward as it has small height and we already got the max width we could get w it. Also advance j if they are equal, i will keep moving until it reaches j. so, in this case, it doesnt really matter which ptr we move, both will work.
        }
        return max;
    }
};

// approach 1: brute force
// time complexity: O(n^2)
// space complexity: O(1)
class Solution0 {
public:
    int maxArea(vector<int>& heights) {
        int max = 0;    
        // check all possible pairs
        for (int i=0; i<heights.size(); i++) {
            for (int j=0; j<heights.size(); j++) { 
                int width = abs(i-j);   // check distance between 2 containers by subtracting their indexes and taking absolute so its always +ve
                int height = min(heights[i], heights[j]);   // min height is the max height till it can store water
                int vol = width * height;
                // keep track of max volume
                if (vol > max)      
                    max = vol;
            }
        }
        return max;
    }
};
