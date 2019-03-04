/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 *
 * https://leetcode.com/problems/subsets/description/
 *
 * algorithms
 * Medium (50.85%)
 * Total Accepted:    331.4K
 * Total Submissions: 649.8K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a set of distinct integers, nums, return all possible subsets (the
 * power set).
 * 
 * Note: The solution set must not contain duplicate subsets.
 * 
 * Example:
 * 
 * 
 * Input: nums = [1,2,3]
 * Output:
 * [
 * ⁠ [3],
 * [1],
 * [2],
 * [1,2,3],
 * [1,3],
 * [2,3],
 * [1,2],
 * []
 * ]
 * 
 */
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> result;
        vector<vector<int>> res;
        if(nums.size()==0) return res;
       // sort(nums.begin(),nums.end());
        
        

        subsets(res,result,nums,0);
        return res;
    }


private:
    void subsets(vector<vector<int>>& res,vector<int>& result,vector<int>& nums,int location){
        res.push_back(result);
        if(location==nums.size()) return;

        for(int i=location;i<nums.size();i++){
         //   if(i>0&&nums[i]==nums[i-1]) continue;
            result.push_back(nums[i]);
            int temp=nums[i];
            nums.erase(nums.begin()+i);
            subsets(res,result,nums,i);
            result.pop_back();
            nums.insert(nums.begin()+i,temp);
        }


        
    }
};

