/*
 * @lc app=leetcode id=1345 lang=cpp
 *
 * [1345] Jump Game IV
 */

/*
    [100, -23, -23, 404, 100, 23, 23, 23, 3, 404]
      0    1    2    3    4   5   6   7   8   9
      * in one step we can move from index i to : i+1
      * from index i to : i-1
      * from index i to j, if arr[i] = arr[j] and i != j
    -> so, the path is from 0 -> 4 -> 3 -> 9
                              1    2    3
        output = 3

            BFS :

    -> we create a hashmap to keep track of the elements of the given array, and the indices where they appear

      HashMap                          _______________________________________
    100  -  [0, 4]            visited |_t_|_t_|_t_|_t_|_t_|_t_|_t_|_t_|__|_t_|   <bool>
    -23  -  [1, 2]                      0   1   2   3   4   5   6   7  8   9
    404  -  [3, 9]                    ___________________________________
     23  -  [5, 6, 7]         queue  |__|__|__|__|__|__|_9_|__|__|__|     <int> 
      3  -  [8]
                              q.pop() -> 0  -> 4 -> 1 -> 3 -> 5 -> 2
                              
                              
                              
                              steps = 0 -> 1 
                               
                               for i = 0
                                      _______________________________
                               next  |_0_|_4_|_1_|_-1_|__|__|__|__|__|
                                       /   /   /   x
                               for i = 4
                                      _______________________________
                               next  |_3_|_5_|_0_|_4_|__|__|__|__|__|
                                       /   /  vis vis
                               for i = 1
                                      _______________________________
                               next  |_1_|_2_|_0_|__|__|__|__|__|__|
                                      vis  /  vis   
                               for i = 3
                                      _______________________________
                               next  |_4_|_2_|_9_|__|__|__|__|__|__|
                                      vis vis  /   
                               for i = 5
                                      _______________________________
                               next  |_4_|_5_|_6_|_7_|__|__|__|__|__|
                                      vis  /   /   /
                               for i = 2
                                      _______________________________
                               next  |_1_|_3_|__|__|__|__|__|__|__|
                                      vis vis
                                for i = 9
                                      _______________________________
                               next  |_0_|_4_|_1_|_-1_|__|__|__|__|__|
                                       /   /   /   x
  

*/


// @lc code=start
class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, vector<int>> ump;
        for(int i=0; i<n; i++) ump[arr[i]].push_back(i);
        vector<bool> visited(n);
        visited[0] = true;
        queue <int> q;
        q.push(0);
        int steps = 0;
        while(!q.empty()){
            for(int s=q.size(); s>0; s--){
                int i = q.front();
                q.pop();
                if(i == n-1) return steps;
                vector<int>& next = ump[arr[i]];
                next.push_back(i-1);
                next.push_back(i+1);
                for(auto j: next){
                    if(j>=0 && j<n && !visited[j]){
                        visited[j] = true;
                        q.push(j);
                    }
                }
                ump[arr[i]].clear();
            }

            steps++;
        }
        return steps;
        
    }
};
// @lc code=end

