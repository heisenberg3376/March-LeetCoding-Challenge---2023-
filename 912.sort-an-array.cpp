/*
 * @lc app=leetcode id=912 lang=cpp
 *
 * [912] Sort an Array
 */

/*   
        -> divide the array until single element is left over, using mergesort() function

                 0  1  2  3  4  5
                [5, 1, 1, 2, 0, 0]
                 l     m        h
                    /         \
                   /           \
            [5, 1, 1]     [2, 0, 0]
             l     m      m+1    h
              /   \          /   \
             /     \        /     \
          [5, 1]   [1]    [2, 0]  [0]
           /  \            /  \
          /    \          /    \
        [5]    [1]      [2]    [0]  


            we call the mergesort() function recursivelty, two times
            for low -> mid and mid+1 -> high.

            mergesort( low, high, arr){
                if(low == high) return;
                else{
                    int mid = (low + high) / 2;
                    mergesort(low, mid, arr);
                    mergesort(mid+1, high, arr);
                    merge(low, mid, high, arr);
                }
            }

        -> after dividing we merge the elements in ascending order

         



*/


// @lc code=start
class Solution {
public:
    void mergesort(vector<int>&nums,int low,int high){
        if (low== high) return;
        int mid = (low+high)/2;
        mergesort(nums,low,mid);
        mergesort(nums,mid+1,high);
        merge(nums,low,high,mid);
        
    }
    void merge(vector<int>&nums,int low,int high,int mid){
        int l = low, r= mid+1;
        vector<int> v;
        while(l<=mid && r<=high){
            if(nums[l]<=nums[r]){
                v.push_back(nums[l]);
                l++;
            }
            else{ v.push_back(nums[r]);r++;}
        }
        while(l<=mid){v.push_back(nums[l]);l++;}
        while(r<=high){v.push_back(nums[r]);r++;}
        for(int i=low;i<=high;i++)nums[i]=v[i-low];
    }
    vector<int> sortArray(vector<int>& nums) {
        mergesort(nums,0,nums.size()-1);
        return nums;
    }
};
// @lc code=end

