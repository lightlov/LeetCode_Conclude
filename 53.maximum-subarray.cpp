/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 *
 * https://leetcode.com/problems/maximum-subarray/description/
 *
 * algorithms
 * Easy (42.73%)
 * Total Accepted:    464K
 * Total Submissions: 1.1M
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * Given an integer array nums, find the contiguous subarray (containing at
 * least one number) which has the largest sum and return its sum.
 * 
 * Example:
 * 
 * 
 * Input: [-2,1,-3,4,-1,2,1,-5,4],
 * Output: 6
 * Explanation: [4,-1,2,1] has the largest sum = 6.
 * 
 * 
 * Follow up:
 * 
 * If you have figured out the O(n) solution, try coding another solution using
 * the divide and conquer approach, which is more subtle.
 * 
 */

/*
methode 1:
先对数组求每一项之前所有项的和，在求两个前缀和之差，则是连续子项和，求其中最大值，
定义一个cur_min,也就是当前项之前项的最小前缀和，使用sum数组。
注意：当nums中全部是正数时，cur_min需要从0开始，以便res加上第一项。
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size()==0 ) return 0;
        if(nums.size()==1) return nums[0];

        vector<int> sum;
        int res=0;
        for(int i=0;i<nums.size();i++){
            res+=nums[i];
            sum.push_back(res);

        }

        res=sum[0];
        cur_min=sum[0];
        for(int i=1;i<sum.size();i++){
            res=max(res,sum[i]-cur_min);
            cur_min=min(cur_min,sum[i]);

        }
        return res;
            
        
    }
};

/*
method 2:
动态规划法。
维护一个sum变量和一个res变量，res变量记录最后返回值，sum变量记录子序列的值，res初始化为nums[0]
首先sum=nums[0],当sum<0时，加入子序列则会导致子序列值减小，因此另起一个子序列，这时比较res和sum的大小，res记录较大值
当sum>0时，子序列可往后延续，这时仍然需要比较res和sum的值，res记录较大值
因为当sum=sum+nums[i]>0时，虽然可以加入子序列，但是nums[i]仍然有可能小于0，但是此时记录res为前一个sum值，也就是较大值，当连续减小至0时，会另起一个子序列。
*/
/*
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size()==0 ) return 0;
        if(nums.size()==1) return nums[0];

        int sum=0;
        int res=nums[0];
        for(int i=0;i<nums.size();i++){
            if(sum>0) sum+=nums[i];
            else sum=nums[i];
            res=max(res,sum);
        }
        
        return res;
            
        
    }
};
*/

