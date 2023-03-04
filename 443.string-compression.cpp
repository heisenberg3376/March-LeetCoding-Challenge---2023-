/*
 * @lc app=leetcode id=443 lang=cpp
 *
 * [443] String Compression
 */

// @lc code=start

/*
    * put a dummy character at the end of the given char array
    * n = length of chars array
    * declare an ans vector
    * declare a variable to keep track of number of occurences t = 1
    * iterate over the array for( i=1; i<n; i++)
    * check if chars[i-1] = chars[i] (previous char = present char)
    * if yes increment t
    * else {
    *   check if t==1 then ans.push_back(chars[i-1]), t=1;
    *   else {
    *       ans.push_back(chars[i-1])
    *       string l = to_string(t)
    *       for(auto it:len) ans.push_back(l)
    *       t = 1
    *   }
    * }
    * chars = ans
    * return ans.size()


*/

class Solution {
public:
    int compress(vector<char>& chars) {
        chars.push_back('~');
        int n = chars.size();
        vector<char> ans;
        int t = 1;
        for(int i=1; i<n;i++){
            if(chars[i] == chars[i-1]) t++;
            else {
                if(t==1) ans.push_back(chars[i-1]),t=1;
                else{
                    ans.push_back(chars[i-1]);
                    string l = to_string(t);
                    for(auto it: l) ans.push_back(it);
                    t = 1;

                }
            }
        }
        chars = ans;
        return ans.size();
    }
};
// @lc code=end

