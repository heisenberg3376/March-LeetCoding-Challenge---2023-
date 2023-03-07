/*
 * @lc app=leetcode id=2187 lang=cpp
 *
 * [2187] Minimum Time to Complete Trips
 */
/*
apply binary search

*/



// @lc code=start
class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long start = 0;
        long long end = LONG_MAX;
        long long mid;

        /*input :  [1, 2, 3], totalTrips = 5

                this is the sequence on which we apply binary search to find the time
                for understanding lets take 10 elements
                0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, ..........INT_MAX
                s              m              e
                
                initial:(mid = 5)     trips = 0
                                    trips = (5/1) + (5/2) + (5/3)
                                    trips = 5+2+1 = 8
                                    8 > 5

                0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, ..........INT_MAX
                s     m        e

                next(mid = 2) :      trips = 0
                                    trips = (2/1) + (2/2) + (2/3)
                                    trips = 2+1+0 = 3
                                    3<5

                0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, ..........INT_MAX
                         s  m  e

                next(mid = 4)        trips = 0
                                    trips = (4/1) + (4/2) + (4/3)
                                    trips = 4+2+1 = 7
                                    7>5

                0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, ..........INT_MAX
                        sm  e
                next(mid=3)       trips = 0
                                    trips = (3/1)+(3/2)+(3/3)
                                    trips = 3+1+1
                                    5 = 5
                0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, ..........INT_MAX
                        sme
                mid = 3            trips = 5
                                    5=5
                0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, ..........INT_MAX
                        ems
                        return s {3}


        output = 3
        */
        
        while(start<end)
        {
            mid = start + (end - start)/2;
            unsigned long long trips = 0; 
            for(int i=0;i<time.size();i++)
                trips+= (mid/time[i]);            
            if(trips < totalTrips) start = mid + 1;
            else end = mid;
        }
        
        return start;
    }
};
// @lc code=end

