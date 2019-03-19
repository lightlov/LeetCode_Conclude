/*
 * @lc app=leetcode id=239 lang=cpp
 *
 * [239] Sliding Window Maximum
 *
 * https://leetcode.com/problems/sliding-window-maximum/description/
 *
 * algorithms
 * Hard (37.18%)
 * Total Accepted:    142.1K
 * Total Submissions: 380.9K
 * Testcase Example:  '[1,3,-1,-3,5,3,6,7]\n3'
 *
 * Given an array nums, there is a sliding window of size k which is moving
 * from the very left of the array to the very right. You can only see the k
 * numbers in the window. Each time the sliding window moves right by one
 * position. Return the max sliding window.
 * 
 * Example:
 * 
 * 
 * Input: nums = [1,3,-1,-3,5,3,6,7], and k = 3
 * Output: [3,3,5,5,6,7] 
 * Explanation: 
 * 
 * Window position                Max
 * ---------------               -----
 * [1  3  -1] -3  5  3  6  7       3
 * ⁠1 [3  -1  -3] 5  3  6  7       3
 * ⁠1  3 [-1  -3  5] 3  6  7       5
 * ⁠1  3  -1 [-3  5  3] 6  7       5
 * ⁠1  3  -1  -3 [5  3  6] 7       6
 * ⁠1  3  -1  -3  5 [3  6  7]      7
 * 
 * 
 * Note: 
 * You may assume k is always valid, 1 ≤ k ≤ input array's size for non-empty
 * array.
 * 
 * Follow up:
 * Could you solve it in linear time?
 */
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        if(nums.size()==0) return res;
        
        int index=find_max(nums,k,0);
        res.push_back(nums[index]);
        
        for(int i=1;i<=nums.size()-k;i++){
            if(nums[i+k-1]>=nums[index]){
                index=i+k-1;
            }
            else if(index>=i){
                
            }
            else{
                index=find_max(nums,k,i);
            }
            res.push_back(nums[index]);
        }
        
        return res;
    }
    
    int find_max(vector<int>& nums,int k,int index){
        //返回第一个滑动窗口的最大值的index。
        
        int res=index;
        for(int i=index;i<index+k;i++){
            if(nums[i]>=nums[res]) res=i;
        }
        
        return res;
    }
};

