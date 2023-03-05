/*
 * @lc app=leetcode id=2444 lang=cpp
 *
 * [2444] Count Subarrays With Fixed Bounds
 */

// @lc code=start

/* 
    [2, 3, 5, 2, 3, 4, 5, 7, 5, 1, 4, 2, 5]
    brute force : find all the subarrays and check if min(subarr) = minK and max(subarr) = maxK

    two Pointer :
            * to keep track of the latest min and max position, we use minPos and maxPos variables, initialize them with -1
            * declare excl variable -> to keep track of the variable, that's outside the bound
            * [ 1, 3, 5, 2, 7, 5], minK = 1, maxK = 5
            * the subarray must not consist the values outside the bound (minK, maxK)
            * iterate over every element in the array
            * check if the i th element is between the bound, if not update excl = i
            * if i th element = minK then minPos = i
            * if i th element = maxK then maxPos = i
            * the answer will be 'min(minPos, maxPos) - excl'
            * return it
 */

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
       // [ 1, 3, 5, 2, 7, 5], minK = 1, maxK = 5
       //  mn          lb mx
       long long ans = 0;
       int minPos = -1, maxPos = -1, excl = -1;
       for(int i=0; i<nums.size(); i++){
        if(nums[i] == minK){
            minPos = i;
        }
        if(nums[i] == maxK){
            maxPos = i;
        }
        if(nums[i] < minK || nums[i] > maxK){
            excl = i;
        }
        ans += max(0, min(minPos,maxPos) - excl);
       } 
       return ans;
    }
};
// @lc code=end

