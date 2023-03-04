/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Find the Index of the First Occurrence in a String
 */

// @lc code=start

/*
    haystack = "sadbutsad", needle = "sad"
    as 'sad'(needle) occurs two times in the 'sadbutsad'(haystack)

    * n = length of needle string
    * m = length of haystack string
    * for(i : 1 -> m-n)
    * check if all the substrings from starting of haystack string of length n are equal to the needle string
    * if yes return i
    * else return -1


*/


class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        for(int i=0; i<n-m+1; i++){
            if(haystack.substr(i, m) == needle) return i;
        }
        return -1;
    }
};
// @lc code=end

