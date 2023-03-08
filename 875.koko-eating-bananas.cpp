/*
 * @lc app=leetcode id=875 lang=cpp
 *
 * [875] Koko Eating Bananas
 */

// @lc code=start
class Solution {
public:
    
    
    /*
    input = [3, 6, 7, 11], h = 8
        
        k=1 : 
            (3/1)hrs -> 1st pile
            
        k=2 :
            (3/2)hrs -> 1st pile
            (6/2)hrs -> 2nd pile
            
        k=3 :
            3/3hr  -> 1st pile
            6/3hrs -> 2nd pile
            7/3hrs -> 3rd pile
            
        k=4 :
            3/4hr  -> 1st pile
            6/4hrs -> 2nd pile
            7/4hrs -> 3rd pile
            11/4hrs -> 4th pile
            
    output = 4
    
    */
    long long timeToEatAllBananas(vector<int>& piles, int bananasPerHour){
        long long totalTime = 0;
        for(int i=0; i<piles.size();i++){
            int time = ceil(piles[i]/(double)bananasPerHour);
            totalTime += time;
        }
        return totalTime;
    }
    
    
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = *max_element(piles.begin(),piles.end());
        int ans = -1;
        while(low <= high){
            int mid = (low + high) / 2;
            if(timeToEatAllBananas(piles, mid) <= h){
                ans = mid;
                high = mid -1 ;
            }
            else low = mid + 1;
        }
        return ans;
    }
};
// @lc code=end

