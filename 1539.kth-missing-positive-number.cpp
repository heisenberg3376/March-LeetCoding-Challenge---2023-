/*
 * @lc app=leetcode id=1539 lang=cpp
 *
 * [1539] Kth Missing Positive Number
 */
/*
               0  1  2  3  4
        arr = [2, 3, 4, 7, 11], k = 5
                        h    
                            l
                            m
    -> 4 - 3 < 5  /
    -> 7 - 4 <5   /
    -> 11 - 5 > 6
    4+5 = 9
    output : 9









*/



// @lc code=start
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int low = 0, high = arr.size()-1;
        while(low <= high){
            int mid = (low + high) / 2;
            if(arr[mid] - (mid + 1) < k) low = mid + 1;
            else high = mid - 1;
        }
        return low + k;
    }
};
// @lc code=end

