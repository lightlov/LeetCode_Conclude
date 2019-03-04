/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 *
 * https://leetcode.com/problems/largest-rectangle-in-histogram/description/
 *
 * algorithms
 * Hard (30.19%)
 * Total Accepted:    158.6K
 * Total Submissions: 524.5K
 * Testcase Example:  '[2,1,5,6,2,3]'
 *
 * Given n non-negative integers representing the histogram's bar height where
 * the width of each bar is 1, find the area of largest rectangle in the
 * histogram.
 * 
 * 
 * 
 * 
 * Above is a histogram where width of each bar is 1, given height =
 * [2,1,5,6,2,3].
 * 
 * 
 * 
 * 
 * The largest rectangle is shown in the shaded area, which has area = 10
 * unit.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: [2,1,5,6,2,3]
 * Output: 10
 * 
 * 
 */
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res=0;
        int x,y;
        for(int i=0;i<heights.size();i++){
            for(x=i;x>=0;i--){
                if(heights[x]<heights[i]) break;
            }


            for(y=i;y<heights,size();y++){
                if(heights[y]<heights[i]) break;
            }

            res=max(res,heights[i]*(y-x-1));
        }

        return res;
    }
};

