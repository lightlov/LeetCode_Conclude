/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 *
 * https://leetcode.com/problems/combinations/description/
 *
 * algorithms
 * Medium (45.90%)
 * Total Accepted:    186K
 * Total Submissions: 404.2K
 * Testcase Example:  '4\n2'
 *
 * Given two integers n and k, return all possible combinations of k numbers
 * out of 1 ... n.
 * 
 * Example:
 * 
 * 
 * Input: n = 4, k = 2
 * Output:
 * [
 * ⁠ [2,4],
 * ⁠ [3,4],
 * ⁠ [2,3],
 * ⁠ [1,2],
 * ⁠ [1,3],
 * ⁠ [1,4],
 * ]
 * 
 * 
 */
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> result;
        vector<vector<int>> res;
        if(k>n||k==0) return res;
        combine(res,result,1,n,k);
        return res;
    }
private:
    void combine(vector<vector<int>>& res, vector<int>& result,int num,int n,int k){
        if(k==0) {res.push_back(result);return ;}
        for(int i=num;i<=n;i++){
            result.push_back(i);
            combine(res,result,i+1,n,k-1);
            result.pop_back();
            
        }
    }
};

