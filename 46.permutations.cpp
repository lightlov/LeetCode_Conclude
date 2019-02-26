/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 *
 * https://leetcode.com/problems/permutations/description/
 *
 * algorithms
 * Medium (53.26%)
 * Total Accepted:    338K
 * Total Submissions: 634.3K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a collection of distinct integers, return all possible permutations.
 * 
 * Example:
 * 
 * 
 * Input: [1,2,3]
 * Output:
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
 * ]
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> result;
        permute(res,result,nums);
        
        return res;
    }
    
private:
    void permute(vector<vector<int>> &res, vector<int>& result,vector<int>& nums){
        //res存放最后答案,result存放当前答案,i表示从nums中取哪个数
        if(nums.size()==0){res.push_back(result);return ;}
        for(int i=0;i<nums.size();i++){
            int num=nums[i];
            result.push_back(nums[i]);
            nums.erase(nums.begin()+i);
            permute(res,result,nums);
            result.pop_back();
            nums.insert(nums.begin()+i,num);
        }
    }
};


